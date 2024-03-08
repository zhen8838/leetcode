#include "commom.hpp"
#include <concepts>
#include <gtest/gtest.h>

template <class T, class Shape, class Strides, bool IsView> class tensor_base {
  // constexpr static bool is_view = IsView;
public:
  static constexpr bool is_view() { return IsView; }
};

template <typename T>
concept IsTensor = std::is_class_v<T> && requires(T t) { T::is_view(); };

template <IsTensor T> void print_tensor_property(T t) { ic(t.is_view()); }

TEST(test_concept, test_is_tensor) {
  tensor_base<float, int[], int[], true> a;
  print_tensor_property(a);
}