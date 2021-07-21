#include <gtest/gtest.h>

#include <iostream>
#include <tuple>
#include <vector>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>

#include "icecream.hpp"
using Shape = xt::svector<size_t, 4>;
using Stride = xt::svector<size_t, 4>;

TEST(test_xtl, xtl_compute_size) {
  Shape shape{1, 8, 8, 2};
  Stride strides{128, 8, 1, 64};
  Stride backstrides{};
  auto size = xt::compute_strides(shape, xt::layout_type::row_major, strides);
  IC(shape);
  IC(strides);
  IC(size);
}