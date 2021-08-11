#include <gtest/gtest.h>

#include <iostream>
#include <tuple>
#include <vector>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>
#include <xtensor/xview.hpp>
#include <bitset>
#include <numeric>

#include "icecream.hpp"
using Shape = xt::svector<size_t, 4>;
using Stride = xt::svector<size_t, 4>;

TEST(test, bfloat16)
{
  const uint32_t max_bfloat16 = 0x7fff;

  float v = 0.27353;
  uint32_t vv = *reinterpret_cast<uint32_t *>(&v);
  IC(std::bitset<32>(vv));
  uint32_t bit = ((vv >> 16) & 1);
  IC(std::bitset<32>(bit));
  uint32_t bias = max_bfloat16 + bit;
  IC(std::bitset<32>(bias));
  vv += bias;
  IC(std::bitset<32>(vv));
  IC(static_cast<int>(vv >> 16));
}

TEST(test_xtl, xtl_compute_size)
{
  Shape shape{1, 8, 8, 2};
  Stride strides{128, 8, 1, 64};
  Stride backstrides{};
  auto size = xt::compute_strides(shape, xt::layout_type::row_major, strides);
  IC(shape);
  IC(strides);
  IC(size);
}

TEST(test_int, int64_to_int)
{
  uint64_t x[] = {
      0x7fffffffffffffff,
      0x7fffffffffffff,
      0x7fffffffffffffa2,
  };
  uint64_t *ptr = x;
  IC(sizeof(int), ptr, ptr + 1);
  IC(*reinterpret_cast<int *>(ptr));
  std::vector<int> vx{ptr, ptr + 1};
  IC(vx);
  IC((int)(*ptr >> 32));
  IC(std::bitset<64>(x));
  IC(std::bitset<64>((int)(*ptr >> 32)));
}

TEST(test_int, int64_to_int_tansform)
{
  const uint64_t ptr[] = {0x7fffffffffffffff,
                          0x7fffffffffffff,
                          0x7fffffffffffffa2,
                          34583};
  size_t size = 4;
  std::vector<int> data;
  data.reserve(size);
  std::transform(ptr, ptr + size, std::back_inserter(data), [](const uint64_t &e) {
    IC(e, static_cast<int>(e));
    int re;
    if (e > (uint64_t)std::numeric_limits<int>::max())
    {
      re = std::numeric_limits<int>::max();
    }
    else
    {
      re = static_cast<int>(e);
    }
    IC(re);
    return (int)e;
  });
}

TEST(test_float, float)
{
  float f = 1.76268616E+10;
  uint32_t u = *reinterpret_cast<uint32_t *>(&f);
  IC(std::bitset<32>(u));
  int mul_shift;
  float mul = std::frexpf(f, &mul_shift);
  IC(mul, mul_shift);
  // ASSERT_EQ(std::bitset<32>(""), std::bitset<32>(23.43));
}