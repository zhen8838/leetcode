#include "commom.hpp"
#include <arm_neon.h>
#include <gtest/gtest.h>

template <class T, size_t... Lanes> struct simd_type {};

template <> struct simd_type<float, 4> {
#ifdef __ARM_NEON__
  using type = float32x4_t;
#endif
};

template <> struct simd_type<float, 2> {
#ifdef __ARM_NEON__
  using type = float32x2_t;
#endif
};

template <> struct simd_type<float, 2, 2> {
#ifdef __ARM_NEON__
  using type = float32x2x2_t;
#endif
};

TEST(simd_type, f32x4) {
  simd_type<float, 4>::type a;
  simd_type<float, 2>::type b;
  simd_type<float, 2, 2>::type c;
}