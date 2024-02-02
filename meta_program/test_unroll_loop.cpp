#include "commom.hpp"
#include <gtest/gtest.h>

namespace detail {

template <size_t OffSet, size_t... Values, size_t... Indices>
static constexpr auto sum_selected(std::index_sequence<Indices...>) {
  return (... * std::get<Indices + OffSet>(std::forward_as_tuple(Values...)));
}

template <size_t Index, size_t... Values> static constexpr auto At() {
  return get<Index>(std::forward_as_tuple(Values...));
}

} // namespace detail

template <size_t... Dims> struct fixed_shape {};

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
