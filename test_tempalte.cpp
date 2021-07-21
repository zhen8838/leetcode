#include <gtest/gtest.h>

#include <iostream>
#include <numbers>
#include <numeric>
#include <tuple>
#include <type_traits>
#include <typeinfo>
#include <vector>

#include "icecream.hpp"

constexpr size_t compute_rsize(size_t Parallel, size_t Stride, size_t Filter)
{
  return Filter + std::min(Stride, Filter) * (Parallel - 1);
}

template <size_t Filter, typename T, size_t N>
void binding_ptr(std::array<T, N> &a, T base, size_t step, size_t start = 0)
{
  for (size_t i = 0; i < Filter; i++)
  {
    a[start + i] = base + step * i;
  }
}

template <size_t Parallel, size_t Stride, size_t Filter, typename T, size_t N>
void binding_ptr(std::array<T, N> &a, T base, size_t step, size_t start = 0)
{
  for (size_t p = 0; p < Parallel; p++)
  {
    binding_ptr<Filter>(a, base + p * Stride * step, step,
                        p * std::min(Filter, Stride));
  }
}

TEST(test_tmp, binding_ptr)
{
  constexpr size_t Parallel = 2, Stride = 4, Filter = 3;
  constexpr size_t r_size = compute_rsize(Parallel, Stride, Filter);
  size_t I_h = 32, I_w = 64;
  float kernel[Filter * Filter];
  std::iota(kernel, kernel + Filter * Filter, 0);
  float image[I_h * I_w];
  std::iota(image, image + I_h * I_w, 0);
  IC(image[0]);
  std::array<float *, r_size> r;
  binding_ptr<Parallel, Stride, Filter>(r, image, I_w);
  IC(r);
  IC(*image);
  IC(*(image + I_w));
  IC(*(image + I_w * 2));
  for (auto &&rr : r)
  {
    IC(*rr);
  }
}

// template <typename T, size_t... W>
// void conv1xM(float& sum, T r, T k, std::index_sequence<W...>) {
//   ((sum += r[W] * k[W]), ...);
// }

// template <size_t Filter_w, typename T, size_t Filter_h, size_t... H>
// void convNxM(float& sum, std::array<T, Filter_h>& r, std::array<T, Filter_h>&
// k,
//              std::index_sequence<H...>) {
//   (conv1xM(sum, r[H], k[H], std::make_index_sequence<Filter_w>{}), ...);
// }

// template <size_t Filter_w, typename T, size_t Filter_h>
// void convNxM(float& sum, std::array<T, Filter_h>& r,
//              std::array<T, Filter_h>& k) {
//   convNxM<Filter_w>(sum, r, k, std::make_index_sequence<Filter_h>{});
// }

// TEST(test_tmp, conv) {
//   constexpr size_t K_h = 3, K_w = 6;
//   size_t I_h = 32, I_w = 64;
//   float kernel[K_h * K_w];
//   std::iota(kernel, kernel + K_h * K_w, 0);
//   float image[I_h * I_w];
//   std::iota(image, image + I_h * I_w, 0);
//   IC(image[0]);

//   std::array<float*, K_h> r{image, image + I_w, image + I_w * 2};
//   std::array<float*, K_h> k{kernel, kernel + K_w, kernel + K_w * 2};
//   float sum = 0.;
//   convNxM<K_w>(sum, r, k);
//   IC(sum);
// }

template <typename Array>
using element_type_t =
    std::remove_reference_t<decltype(*std::begin(std::declval<Array &>()))>;

template <size_t N = 20, typename Array>
auto get_same_type_array(Array &a, element_type_t<Array> b)
{
  std::array<element_type_t<Array>, N> c{b};
  return c;
}

TEST(test_tmp, test_get_array_type)
{
  constexpr size_t K_h = 3, K_w = 6;
  size_t I_h = 32, I_w = 64;
  float kernel[K_h * K_w];
  std::iota(kernel, kernel + K_h * K_w, 0);
  float image[I_h * I_w];
  std::iota(image, image + I_h * I_w, 0);
  IC(image[0]);

  std::array<float *, K_h> r{image, image + I_w, image + I_w * 2};
  std::array<float *, K_h> k{kernel, kernel + K_w, kernel + K_w * 2};
  auto b = get_same_type_array<5>(r, image);
  IC(b);
}

template <typename Array>
void pass_diff_len_array(Array &a, Array &b)
{
  IC(a[0], *b.end());
}

TEST(test_tmp, test_pass_diff_len_array) {}
// template <size_t Parallel, size_t Filter_w, size_t Filter_h, typename Array>
// void ParallelconvNxM(float& sum, std::array<T, Filter_h>& r,
//                      std::array<T, Filter_h>& k) {}

template <typename T, size_t... W>
void conv1xM(T &sum, T *r, T *k, std::index_sequence<W...>)
{
  ((sum += r[W] * k[W]), ...);
}

template <size_t R, size_t Filter_h, size_t Filter_w, typename T, size_t N,
          size_t... H>
void convNxM(T &sum, std::array<T *, N> &r, std::array<T *, Filter_h> &k,
             std::index_sequence<H...>)
{
  (conv1xM(sum, r[R + H], k[H], std::make_index_sequence<Filter_w>{}), ...);
}

template <size_t R, size_t Filter_h, size_t Filter_w, typename T, size_t N>
void convNxM(T &sum, std::array<T *, N> &r, std::array<T *, Filter_h> &k)
{
  convNxM<R, Filter_h, Filter_w>(sum, r, k,
                                 std::make_index_sequence<Filter_h>{});
}

template <size_t Parallel, size_t P, size_t Stride_h, size_t Filter_h,
          size_t Filter_w, typename T, size_t N>
void convNxM(std::array<T, Parallel> &sum, std::array<T *, N> &r,
             std::array<T *, Filter_h> &k)
{
  IC(P * std::min(Stride_h, Filter_h));
  convNxM<P * std::min(Stride_h, Filter_h), Filter_h, Filter_w>(sum[P], r, k);
  if constexpr (P < Parallel - 1)
  {
    convNxM<Parallel, P + 1, Stride_h, Filter_h, Filter_w, T, N>(sum, r, k);
  }
}

TEST(test_tmp, multi_conv)
{
  constexpr size_t Parallel = 2, Stride_h = 4, Stride_w = 2, Filter_h = 3,
                   Filter_w = 3;
  constexpr size_t r_size = compute_rsize(Parallel, Stride_h, Filter_h);
  size_t I_h = 32, I_w = 64;
  float kernel[Filter_h * Filter_w];
  std::iota(kernel, kernel + Filter_h * Filter_w, 0);
  float image[I_h * I_w];
  std::iota(image, image + I_h * I_w, 0);
  std::array<float *, r_size> r;
  std::array<float *, Filter_h> k;
  binding_ptr<Parallel, Stride_h, Filter_h>(r, image, I_w);
  binding_ptr<Filter_h>(k, kernel, Filter_w);
  std::array<float, Parallel> sum;
  std::fill_n(sum.begin(), Parallel, 0);
  for (size_t p = 0; p < Parallel; p++)
  {
    int s = 0;
    for (size_t h = 0; h < Filter_h; h++)
    {
      for (size_t w = 0; w < Filter_w; w++)
      {
        IC(*(r[p * std::min(Stride_h, Filter_h) + h] + w), *(k[h] + w));
        s += *(r[p * std::min(Stride_h, Filter_h) + h] + w) * *(k[h] + w);
      }
    }
    IC(p, s);
  }

  convNxM<Parallel, 0, Stride_h, Filter_h, Filter_w>(sum, r, k);
  IC(sum);
}

class Mat
{
public:
  float *data;
  Mat() { data = new float[100]; }
  ~Mat(){};
};

template <typename T>
void make_mat(T &m)
{
  if constexpr (std::is_pointer<T>())
  {
    IC(std::string("is pointer"));
    m[0] = 100;
  }
  else
  {
    IC(std::string("is Mat"));
    m.data[0] = 100;
  }
}

TEST(test_tmp, integral_constant)
{
  Mat m1;
  float *m2 = new float[10];
  make_mat(m1);
  make_mat(m2);
}