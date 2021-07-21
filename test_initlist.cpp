#include <gtest/gtest.h>

#include <commom.hpp>
using namespace std;

// std::initializer_list
using shape_t = array<size_t, 4>;

struct Conv2dParam {
  shape_t in_shape;
  size_t out_channels;
  shape_t kernel_size;
  shape_t padding;
};

std::vector<Conv2dParam> Conv2dParams{
    {{1, 2, 3, 4}, 32, {3, 3}, {1, 1}},
};

template <typename... Ts>
tuple<Ts...> func(Ts... args) {
  return tuple<Ts...>(args...);
}

TEST(test, initlist_concat) {
  IC(Conv2dParams[0].in_shape);
  auto t = func(1, 2, 4, 5);
  IC(t);
  // testing::Range<size_t> r(0, 10);
  auto v = testing::Values(1, 2, 3, 4);
  // v.MakeVector()
  auto b = testing::Bool();
  auto vin = testing::ValuesIn(shape_t{1, 224, 224, 3});
  auto combined = testing::Combine(v, b, vin);
  // ParamGenerator<::std::tuple<T...>>
  // auto xx = combined();
  // auto fuck =
  //     testing::TestWithParam<tuple<size_t, bool, shape_t>>(combined);
  // IC(v);
}

class TestCombine
    : public testing::TestWithParam<tuple<shape_t, size_t, shape_t, shape_t>> {
 public:
  void SetUp() override {}
  void TearDown() override {}
  // void run() {

  //  }
};
auto in_shapes =
    testing::Values(shape_t{1, 2, 3}, shape_t{4, 5, 6}, shape_t{7, 8, 9});
auto out_channels = testing::Values<size_t, size_t, size_t>(1, 2, 3);
auto kernel_sizes =
    testing::Values(shape_t{1, 3}, shape_t{4, 6}, shape_t{8, 9});
auto paddings = testing::Values(shape_t{1, 3}, shape_t{4, 6}, shape_t{8, 9});
auto combined =
    testing::Combine(in_shapes, out_channels, kernel_sizes, paddings);

TEST_P(TestCombine, g_test_combine) {
  // run();
  auto [in_shape, out_channel, kernel_size, padding] = GetParam();
  Conv2dParam conv2dparam{in_shape, out_channel, kernel_size, padding};
  IC(in_shape, out_channel, kernel_size, padding);
  IC(conv2dparam.kernel_size);
}

INSTANTIATE_TEST_SUITE_P(case1, TestCombine, combined);