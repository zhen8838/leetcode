#include "commom.hpp"
#include <gtest/gtest.h>

template <uint64_t N> struct binary {
  static const uint64_t value = N % 10 + binary<N / 10>::value * 2;
};

template <> struct binary<0> {
  static const uint64_t value = 0;
};

TEST(test_week1, chapter_1_4) {
  // NOTE
  // 编译期生成的数据如果直接传递给一些参数,会报错link失败,因此需要先存储他们
  const auto a = binary<101010>::value;
  const auto b = binary<1>::value;
  ic(a);
  ic(b);
}

// from lib
template <typename T> void dispatcher();

template <> void dispatcher<float>() { std::cout << ("float") << std::endl; }

template <typename T> void invoke() { dispatcher<T>(); }

// from me
template <> void dispatcher<int>() { std::cout << ("int") << std::endl; }

TEST(test_week1, unorderd_instance) {
  invoke<float>();
  invoke<int>();
}