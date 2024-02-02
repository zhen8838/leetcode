#include "commom.hpp"
#include <gtest/gtest.h>

template <size_t... Index> struct reducer {
  template <class T, size_t Size>
  constexpr T operator()(const std::array<T, Size> &input) {
    return (0 + ... + input[Index]);
  }

  template <class T, size_t Size>
  static constexpr T eval(const std::array<T, Size> &input) {
    return (0 + ... + input[Index]);
  }
};

template <size_t... Dims> struct fixed_shape {
  size_t size = sizeof...(Dims);
};

TEST(test_unroll_loop, sum_values) {
  constexpr std::array<size_t, 4> a = {16, 48, 64, 4};
  // NOTE 只有静态类成员才能直接调用
  constexpr auto x = reducer<2, 1>::eval(a);
  // NOTE 对于operator () 来说只能定义后调用,
  // 但如果是符合常量表达式的输入还是可以提前执行。
  reducer<2, 3> r;
  ic(r(a));
  constexpr auto b = r(a);
  constexpr std::array<size_t, 4> stride = {reducer<1, 2, 3>::eval(a),
                                            reducer<2, 3>::eval(a),
                                            reducer<3>::eval(a), 1};
  // NOTE 也可以放到类型参数中
  fixed_shape<reducer<1, 2, 3>::eval(a), reducer<2, 3>::eval(a),
              reducer<3>::eval(a), 1>
      strides{};
}
