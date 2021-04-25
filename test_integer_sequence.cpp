#include <array>
#include <iostream>
#include <tuple>
#include <utility>

// 调试辅助
template <typename T, T... ints>
void print_sequence(std::integer_sequence<T, ints...> int_seq) {
  std::cout << "The sequence of size " << int_seq.size() << ": ";
  ((std::cout << ints << ' '), ...);
  std::cout << '\n';
}

// 转换数组为 tuple
template <typename Array, std::size_t... I>
auto a2t_impl(const Array& a, std::index_sequence<I...>) {
  return std::make_tuple(a[I]...);
}

template <typename T, std::size_t N,
          typename Indices = std::make_index_sequence<N>>
auto a2t(const std::array<T, N>& a) {
  return a2t_impl(a, Indices{});
}

// 漂亮地打印 tuple

template <class Ch, class Tr, class Tuple, std::size_t... Is>
void print_tuple_impl(std::basic_ostream<Ch, Tr>& os, const Tuple& t,
                      std::index_sequence<Is...>) {
  ((os << (Is == 0 ? "" : ", ") << std::get<Is>(t)), ...);
}

template <class Ch, class Tr, class... Args>
auto& operator<<(std::basic_ostream<Ch, Tr>& os, const std::tuple<Args...>& t) {
  os << "(";
  print_tuple_impl(os, t, std::index_sequence_for<Args...>{});
  return os << ")";
}

int buildmat(int a, int b, int c) { return a * b * c; }
int buildmat(int a, int b) { return a * b; }
int buildmat(int a) { return a; }


template <typename... Ints>
void callmat(Ints... nums) {
  std::cout << buildmat(nums...) << std::endl;
}

template <typename T, T... ints>
void getmat(std::integer_sequence<T, ints...> int_seq) {
  std::cout << buildmat(ints...) << std::endl;
}

int main() {
  callmat(1);
  callmat(1, 2);
  callmat(1, 2, 3);
  getmat(std::integer_sequence<int, 9, 2, 5>{});
  // std::integer_sequence<int, 3> in_shape{};
  // in_shape[0] = 2;
  // in_shape[1] = 3;
  // in_shape[2] = 4;
  // getmat(in_shape);
  print_sequence(std::make_integer_sequence<int, 20>{});
  print_sequence(std::make_index_sequence<10>{});
  print_sequence(std::index_sequence_for<float, std::iostream, char>{});

  // std::array<int, 4> array = {1, 2, 3, 4};

  // // 转换 array 为 tuple
  // auto tuple = a2t(array);
  // static_assert(
  //     std::is_same<decltype(tuple), std::tuple<int, int, int, int>>::value,
  //     "");

  // // 打印到 cout
  // std::cout << tuple << '\n';
}
