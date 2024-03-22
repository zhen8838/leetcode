#include "commom.hpp"
#include <concepts>
#include <gtest/gtest.h>

template <class T, class Shape, class Strides, bool IsView> class tensor_base {
  // constexpr static bool is_view = IsView;
public:
  static constexpr bool is_view() { return IsView; }

  static constexpr auto shape() { return Shape{}; }
};

template <typename T>
concept IsTensor = T::is_view() == true;

template <IsTensor T> void print_tensor_property(T t) { ic(t.is_view()); }

template <class TA, class TB> struct tensor_add;

template <IsTensor TA, IsTensor TB> struct tensor_add<TA, TB> {};

TEST(test_concept, test_is_tensor) {
  tensor_base<float, int[], int[], true> a;
  print_tensor_property(a);
  tensor_base<float, int[], int[], true> c;
  tensor_base<float, int[], int[], true> d;
  tensor_add<decltype(c), decltype(d)> add;
}

template <typename TA, typename TB>
  requires std::is_convertible_v<TA, TB>
inline TA from_other(TB b) {
  return b;
}

TEST(test_concept, test_cast) {
  auto a = from_other<float>(12);
  ic(std::is_assignable<int, float>::value);
  ic(std::is_convertible<float, int>::value);
}

template <typename TA, typename TB> struct tensor_mul_impl {
  void operator()(const TA &a, TB &b) { return; }
};
template <typename TA, typename TB> void tensor_mul(const TA &a, TB &&b) {
  tensor_mul_impl<TA, std::decay_t<TB>> impl;
  impl(a, b);
}

TEST(test_concept, test_template_struct_impl_match) {
  tensor_base<float, int[], int[], true> a;
  tensor_base<float, int[], int[], true> c;
  tensor_mul(a, c);
}
