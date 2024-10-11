#include "commom.hpp"
#include <arm_neon.h>
#include <gtest/gtest.h>

void ref_vfma(float32_t a[4], float32_t b[4], float32_t c, float32_t d[4]) {
  for (size_t i = 0; i < 4; i++) {
    d[i] = (a[i] + (b[i] * c));
  }
}

TEST(test_vfma, vfma1) {
  float32x4_t a, b;
  float32_t c = 3;
  float32_t ap[4] = {1, 2, 3, 4};
  float32_t bp[4] = {2, 2, 2, 2};
  float32_t dpr[4];
  float32_t dp[4];

  a = vld1q_f32(ap);
  b = vld1q_f32(bp);
  // vfmaq_lane_f32(a, b, c, d);
  // a += b * c.broadcast

  // 
  auto d = vfmaq_n_f32(a, b, c);
  vst1q_f32(dp, d);
  ref_vfma(ap, bp, c, dpr);

  ic(dp);
  ic(dpr);
  // for (size_t i = 0; i < 4; i++) {
  //   assert(dp[i] == dpr[i]);
  // }
}