#include "commom.hpp"
#include <gtest/gtest.h>

namespace detail {
template <size_t... Dims> struct fixed_dims_base {
  static constexpr size_t rank() noexcept { return sizeof...(Dims); }

  static constexpr size_t at(size_t index) noexcept {
    return std::array<size_t, sizeof...(Dims)>{Dims...}[index];
  }

  constexpr size_t operator[](size_t index) const noexcept { return at(index); }
};

template <size_t OffSet, size_t... Values, size_t... Indices>
static constexpr auto sum_selected(std::index_sequence<Indices...>) {
  return (... * std::get<Indices + OffSet>(std::forward_as_tuple(Values...)));
}

template <size_t Index, size_t... Values> static constexpr auto At() {
  return get<Index>(std::forward_as_tuple(Values...));
}

template <template <size_t...> class T, size_t... ADims, size_t... BDims,
          size_t... I>
inline constexpr bool is_same_seq(const T<ADims...> &a, const T<BDims...> &b,
                                  std::index_sequence<I...>) {
  return ((a[I] == b[I]) && ...);
}

} // namespace detail

template <size_t... Dims>
struct fixed_shape : detail::fixed_dims_base<Dims...> {
  template <size_t I> struct prepend {
    using type = fixed_shape<I, Dims...>;
  };

  template <size_t I> struct append {
    using type = fixed_shape<Dims..., I>;
  };

  static constexpr size_t length() noexcept { return (Dims * ... * 1); }
};

template <size_t Start, size_t... Dims>
static constexpr size_t sum_from_index(const fixed_shape<Dims...> &) {
  return detail::sum_selected<Start, Dims...>(
      std::make_index_sequence<(sizeof...(Dims)) - Start>{});
}

// NOTE 在O1的情况下虽然并没有展开，但是会被优化成非常simple的循环
template <size_t Axis, size_t... Dims, size_t Size, class Callable>
static constexpr void apply_next(std::array<size_t, Size> &index,
                                 Callable &&callable) {
  if constexpr (Axis < sizeof...(Dims)) {
    for (size_t i = 0; i < detail::At<Axis, Dims...>(); i++) {
      index[Axis] = i;
      apply_next<Axis + 1, Dims...>(index, callable);
    }
  } else {
    callable(index);
  }
}

// NOTE 这样好像已经unroll了
template <class F, size_t... I>
constexpr void loop_impl(F &&f, std::index_sequence<I...>) {
  // NOTE index_sequence 是直接存储index 数据
  (f(I), ...);
}

template <size_t N, class F> constexpr void loop(F &&f) {
  // NOTE make_index_sequence 等价于python的range数据
  loop_impl(std::forward<F>(f), std::make_index_sequence<N>{});
}

// NOTE 对于一个函数，只需要他是无副作用的，那么就可以在编译期求constexpr
template <size_t... Dims, class Callable>
static constexpr void apply(fixed_shape<Dims...>, Callable &&callable) {
  std::array<size_t, sizeof...(Dims)> index = {0};
  apply_next<0, Dims...>(index, callable);
}

TEST(test_unroll_loop, apply) {
  fixed_shape<16, 48, 64> sa;
  apply(sa, [](auto &arr) { ic(arr); });
}

TEST(test_unroll_loop, sum_values) {
  fixed_shape<16, 48, 64> sa;
  ic(sum_from_index<1>(sa));
}

TEST(test_unroll_loop, loop) {
  int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  loop<10>([&arr](auto i) { ic(arr[i]); });
}

template <size_t... Args> size_t constexpr cumprod = 0;

template <size_t First, size_t... Rests>
size_t constexpr cumprod<First, Rests...> =
    (First * ... * Rests) + cumprod<Rests...>;

TEST(test_cum_sum, cum_sum) { ic(cumprod<1, 2, 3, 4, 5>); }

template <template <size_t...> class T, size_t... ADims, size_t... BDims>
inline constexpr bool is_same_seq(const T<ADims...> &a, const T<BDims...> &b) {
  return sizeof...(ADims) == sizeof...(BDims) &&
         detail::is_same_seq(a, b,
                             std::make_index_sequence<sizeof...(ADims)>{});
}

TEST(test_is_same_seq, is_same_seq) {
  ic(is_same_seq(fixed_shape<1, 2, 3>{}, fixed_shape<1, 2, 3>{}));
}

template <typename Shape> struct fixed_tensor {
  using shape_type = Shape;
  static constexpr auto shape() { return Shape{}; }
};

template <typename T> void foo(const T t) {
  static_assert(is_same_seq(t.shape(), typename T::shape_type{}), "fuck!");
}

TEST(test_clang_bug, can_not_detect_constexpr) {
  fixed_tensor<fixed_shape<1, 2, 3, 4>> t;
  foo(t);
}

