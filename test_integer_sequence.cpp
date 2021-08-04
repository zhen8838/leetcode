
#include "commom.hpp"
#include "to_tuple.h"
#include <gtest/gtest.h>

// 调试辅助
template <typename T, T... ints>
void print_sequence(std::integer_sequence<T, ints...> int_seq)
{
  std::cout << "The sequence of size " << int_seq.size() << ": ";
  ((std::cout << ints << ' '), ...);
  std::cout << '\n';
}

// 转换数组为 tuple
template <typename Array, std::size_t... I>
auto a2t_impl(const Array &a, std::index_sequence<I...>)
{
  return std::make_tuple(a[I]...);
}

template <typename T, std::size_t N,
          typename Indices = std::make_index_sequence<N>>
auto a2t(const std::array<T, N> &a)
{
  return a2t_impl(a, Indices{});
}

// 漂亮地打印 tuple

template <class Ch, class Tr, class Tuple, std::size_t... Is>
void print_tuple_impl(std::basic_ostream<Ch, Tr> &os, const Tuple &t,
                      std::index_sequence<Is...>)
{
  ((os << (Is == 0 ? "" : ", ") << std::get<Is>(t)), ...);
}

template <class Ch, class Tr, class... Args>
auto &operator<<(std::basic_ostream<Ch, Tr> &os, const std::tuple<Args...> &t)
{
  os << "(";
  print_tuple_impl(os, t, std::index_sequence_for<Args...>{});
  return os << ")";
}

int buildmat(int a, int b, int c) { return a * b * c; }
int buildmat(int a, int b) { return a * b; }
int buildmat(int a) { return a; }

template <typename... Ints>
void callmat(Ints... nums)
{
  std::cout << buildmat(nums...) << std::endl;
}

template <typename T, T... ints>
void getmat(std::integer_sequence<T, ints...> int_seq)
{
  std::cout << buildmat(ints...) << std::endl;
}

template <size_t... Ns>
using seq = typename std::index_sequence<Ns...>;

// tail impl
template <typename T>
struct tail
{
};

template <size_t Ns>
struct tail<seq<Ns>>
{
  constexpr static size_t value = Ns;
};

template <size_t Ns, size_t... Ne>
struct tail<seq<Ns, Ne...>>
{
  constexpr static size_t value = tail<seq<Ne...>>::value;
};

// cumsum, 从左边的参数里面拿到最后一个值,和右边的seq的第一个值进行计算,然后pop右边的第一个值,继续递归
template <typename R, typename L>
struct cumsum
{
};

template <size_t... Ls, size_t Rs>
struct cumsum<seq<Ls...>, seq<Rs>>
{
  using type = seq<Ls...>;
};

template <size_t... Ls, size_t Rs, size_t... Re>
struct cumsum<seq<Ls...>, seq<Rs, Re...>>
{
  using type = typename cumsum<seq<Ls..., tail<seq<Ls...>>::value + Rs>, seq<Re...>>::type;
};

template <size_t Rs, size_t... Re>
struct cumsum<seq<>, seq<Rs, Re...>>
{
  using type = typename cumsum<seq<0>, seq<Rs, Re...>>::type;
};

TEST(test, cumprod)
{
  print_sequence(cumsum<seq<>, seq<3, 1, 2, 3, 4>>::type{});
}

constexpr size_t MAX_MODULE_TYPE_LENGTH = 16;

using module_type_t = std::array<char, MAX_MODULE_TYPE_LENGTH>;

using memory_location_t = uint8_t;

namespace impl
{
  template <typename T>
  struct is_std_array : std::false_type
  {
  };

  template <typename T, size_t N>
  struct is_std_array<std::array<T, N>> : std::true_type
  {
  };

  template <typename T>
  constexpr static bool is_std_array_v = is_std_array<T>::value;

  template <typename T1, typename T2, size_t... Is>
  constexpr void array_copy(T1 *dest, T2 *src, size_t start, std::index_sequence<Is...>)
  {
    static_assert(sizeof(T1) == sizeof(T2), "the dest size must equal src size");
    ((*(dest + start + Is) = *(src + Is)), ...);
  }

  template <typename T, size_t... Is>
  constexpr void assgin_to_array(std::array<uint8_t, sizeof(T)> &dest, const T &src, std::index_sequence<Is...>)
  {
    if constexpr (std::is_integral_v<T>)
    {
      ((dest[Is] = (src >> (Is * 8))), ...);
    }
    else if constexpr (is_std_array_v<T>)
    {
      array_copy(dest.data(), src.data(), 0, std::index_sequence<Is...>{});
    }
    else
    {
      static_assert(sizeof(T) == 0, "the type can't assgin to array");
    }
  }

} // namespace impl

namespace std
{
  // NOTE the operator+ for tuple fold expression must decl in std;
  template <typename T, size_t N, size_t M>
  constexpr std::array<T, N + M> operator+(const std::array<T, N> &a, const std::array<T, M> &b)
  {
    std::array<T, N + M> c{};
    impl::array_copy(c.data(), a.data(), 0, std::make_index_sequence<N>{});
    impl::array_copy(c.data(), b.data(), N, std::make_index_sequence<M>{});
    return c;
  }

} // namespace

template <typename T>
constexpr std::array<uint8_t, sizeof(T)> to_array(const T &v)
{
  std::array<uint8_t, sizeof(T)> arr{};
  impl::assgin_to_array(arr, v, std::make_index_sequence<sizeof(T)>{});
  return arr;
};

TEST(test, to_array)
{
  constexpr uint64_t a = 0x42325;
  constexpr uint32_t b = 0x1212121;
  constexpr uint16_t c = 0x2313;
  constexpr auto a_ = to_array(a);
  constexpr auto b_ = to_array(b);
  constexpr auto c_ = to_array(c);
  ic(std::bitset<64>(*(uint64_t *)a_.data()));
  ic(std::bitset<32>(*(uint32_t *)b_.data()));
  ic(std::bitset<16>(*(uint16_t *)c_.data()));
  // NOTE toarray can't detail float
  constexpr module_type_t m = {'H', 'E', 'L', 'L', 'O'};
  constexpr auto m_ = to_array(m);
  ic(m_);
}

TEST(test, array_concat)
{
  constexpr uint64_t a = 0x42325;
  constexpr auto a_ = to_array(a);
  ic(std::bitset<64>(*(uint64_t *)a_.data()));
  // NOTE toarray can't detail float
  constexpr module_type_t m = {'H', 'E', 'L', 'L', 'O'};
  constexpr auto m_ = to_array(m);
  constexpr auto x = a_ + m_;
  ic(x);
}

namespace impl
{
  template <typename... Tp, size_t... Is>
  constexpr std::array<uint8_t, (sizeof(Tp) + ...)> tuple_to_array(const std::tuple<Tp...> &v, std::index_sequence<Is...>)
  {
    return (to_array(std::get<Is>(v)) + ...);
  };

} // namespace impl

template <typename... Tp>
constexpr std::array<uint8_t, (sizeof(Tp) + ...)> to_array(const std::tuple<Tp...> &v)
{
  return impl::tuple_to_array(v, std::make_index_sequence<sizeof...(Tp)>{});
};

struct mempool_desc
{
  memory_location_t location;
  uint32_t size;
};

struct section_header
{
  module_type_t name;
  uint32_t flags;
  uint32_t start;
  uint32_t size;
  uint32_t reserved0;
};

TEST(test, tuple)
{
  constexpr section_header h{
      {'H', 'E', 'L', 'L', 'O'},
      0x11,
      0x22,
      0x33,
      0x44};
  // //
  constexpr auto t = to_tuple(h);
  ic(sizeof(std::get<0>(t)));
  ic(sizeof(t));
  constexpr auto arr = to_array(t);
  ic(arr);

  constexpr auto a = is_braces_constructible<section_header, any_type, any_type, any_type>{};
  constexpr auto b = is_braces_constructible<section_header, any_type, any_type, any_type, any_type>{};
  constexpr auto c = is_braces_constructible<section_header, any_type, any_type, any_type, any_type, any_type>{};
  constexpr auto d = is_braces_constructible<section_header, any_type, any_type, any_type, any_type, any_type, any_type, any_type, any_type, any_type, any_type>{};
  ic(a);
  ic(b);
  ic(c);
  ic(d);
}
