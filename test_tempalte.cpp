#include <gtest/gtest.h>

#include <iostream>
#include <numbers>
#include <numeric>
#include <tuple>
#include <vector>

#include "icecream.hpp"

constexpr size_t compute_rsize(size_t Parallel, size_t Stride, size_t Filter) {
  return Filter + std::min(Stride, Filter) * (Parallel - 1);
}

template <size_t Filter, typename T, size_t N>
void binding_ptr(std::array<T, N> &a, T base, size_t step, size_t start = 0) {
  for (size_t i = 0; i < Filter; i++) {
    a[start + i] = base + step * i;
  }
}

template <size_t Parallel, size_t Stride, size_t Filter, typename T, size_t N>
void binding_ptr(std::array<T, N> &a, T base, size_t step, size_t start = 0) {
  for (size_t p = 0; p < Parallel; p++) {
    binding_ptr<Filter>(a, base + p * Stride * step, step, p * Filter);
  }
}

TEST(test_tmp, binding_ptr) {
  constexpr size_t Parallel = 2, Stride = 2, Filter = 3;
  size_t I_h = 32, I_w = 64;
  float kernel[Filter * Filter];
  std::iota(kernel, kernel + Filter * Filter, 0);
  float image[I_h * I_w];
  std::iota(image, image + I_h * I_w, 0);
  IC(image[0]);
  constexpr size_t r_size = compute_rsize(Parallel, Stride, Filter);
  std::array<float*, r_size> r;
  binding_ptr<Parallel, Stride, Filter>(r, image, I_w);
  IC(r);
  IC(*image);
  IC(*(image + I_w));
  IC(*(image + I_w * 2));
  for (auto&& rr : r) { IC(*rr); }
}

template <typename T, size_t... W>
void conv1xM(float& sum, T r, T k, std::index_sequence<W...>) {
  ((sum += r[W] * k[W]), ...);
}

template <size_t Filter_W, typename T, size_t Filter_H, size_t... H>
void convNxM(float& sum, std::array<T, Filter_H>& r, std::array<T, Filter_H>& k,
             std::index_sequence<H...>) {
  (conv1xM(sum, r[H], k[H], std::make_index_sequence<Filter_W>{}), ...);
}

template <size_t Filter_W, typename T, size_t Filter_H>
void convNxM(float& sum, std::array<T, Filter_H>& r,
             std::array<T, Filter_H>& k) {
  convNxM<Filter_W>(sum, r, k, std::make_index_sequence<Filter_H>{});
}

TEST(test_tmp, conv) {
  constexpr size_t K_h = 3, K_w = 6;
  size_t I_h = 32, I_w = 64;
  float kernel[K_h * K_w];
  std::iota(kernel, kernel + K_h * K_w, 0);
  float image[I_h * I_w];
  std::iota(image, image + I_h * I_w, 0);
  IC(image[0]);

  std::array<float*, K_h> r{image, image + I_w, image + I_w * 2};
  std::array<float*, K_h> k{kernel, kernel + K_w, kernel + K_w * 2};
  float sum = 0.;
  convNxM<K_w>(sum, r, k);
  IC(sum);
}

template <typename Array>
using element_type_t =
    std::remove_reference_t<decltype(*std::begin(std::declval<Array&>()))>;

template <size_t N = 20, typename Array>
auto get_same_type_array(Array& a, element_type_t<Array> b) {
  std::array<element_type_t<Array>, N> c{b};
  return c;
}

TEST(test_tmp, test_get_array_type) {
  constexpr size_t K_h = 3, K_w = 6;
  size_t I_h = 32, I_w = 64;
  float kernel[K_h * K_w];
  std::iota(kernel, kernel + K_h * K_w, 0);
  float image[I_h * I_w];
  std::iota(image, image + I_h * I_w, 0);
  IC(image[0]);

  std::array<float*, K_h> r{image, image + I_w, image + I_w * 2};
  std::array<float*, K_h> k{kernel, kernel + K_w, kernel + K_w * 2};
  auto b = get_same_type_array<5>(r, image);
  IC(b);
}

template <typename Array>
void pass_diff_len_array(Array& a, Array& b) {
  IC(a[0], *b.end());
}

TEST(test_tmp, test_pass_diff_len_array) {}
// template <size_t Parallel, size_t Filter_W, size_t Filter_H, typename Array>
// void ParallelconvNxM(float& sum, std::array<T, Filter_H>& r,
//                      std::array<T, Filter_H>& k) {}

// template <size_t Parallel, size_t Filter_W, size_t Filter_H, typename Array>
// void ParallelconvNxM(float& sum, std::array<T, Filter_H>& r,
//                      std::array<T, Filter_H>& k) {
//   if constexpr (Parallel > 1) {}
//   convNxM<Filter_W>(sum, r, k, std::make_index_sequence<Filter_H>{});
// }