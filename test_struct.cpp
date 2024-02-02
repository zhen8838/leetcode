#include "commom.hpp"
#include "gtest/gtest.h"

// struct A
// {
//   std::array<uint8_t, 16> arr;
//   uint16_t data;
//   uint64_t u64;
// };

// struct CCRCLR
// {
//   uint64_t ccr_clr : 1; /** 是否需要将某个 CCR 减 1 **/
//   uint64_t ccr : 6;     /** 指明使用哪个 CCR **/
//   uint64_t ccr_acq : 1; /** 是否需要等待某个ccr **/
//   constexpr CCRCLR(uint64_t value = 0) : ccr_clr(value),
//                                          ccr(value),
//                                          ccr_acq(value) {}
//   constexpr uint64_t value() const noexcept
//   {
//     return (uint64_t)ccr_clr;
//   }
//   constexpr operator uint64_t() const noexcept
//   {
//     return value();
//   }
// };

// // template <typename T>
// // struct inst_xxx_t
// // {
// // };

// // template <typename T, typename... Args>
// // constexpr const T &emit(Args... args)
// // {
// //   constexpr T t{args...};
// //   return t;
// // }

// struct inst_xxxx_s
// {
//   uint16_t data = uint16_t(0);
//   uint64_t u64 = uint64_t(0);
//   CCRCLR ccr = CCRCLR(0);
// };

// TEST(test, stuct_A)
// {

//   inst_xxxx_s s{.data = 10};
//   ic(s.u64);

//   // auto a = get<A>({{1, 2, 3, 4}, 2, 3});
//   // auto b = get<inst_xxxx_s>({1, 2, CCRCL R(0)});
//   // constexpr static inst_xxxx_s s{uint16_t(1), uint64_t(2), CCRCLR(0)};

//   // auto v = emit<inst_xxxx_s>(uint16_t(1), uint64_t(2), CCRCLR(0));
//   // constexpr static inst_xxx_t<inst_xxxx_s{uint16_t(1), uint64_t(2), CCRCLR(0)}>{};
//   // inst_xxx_t<get_a<inst_xxxx_s>(uint16_t(1), uint64_t(2), CCRCLR(0))>{};
// }

// template <uint16_t data = 0,
//           uint64_t u64 = 0,
//           uint64_t ccr = 0>
// struct inst_xxx_t
// {
//   using type = std::index_sequence<data, u64, ccr>;
// };

// // template <uint64_t... Values>
// // struct inst_xxx_t_v2
// // {
// //   using type = std::index_sequence<data, u64, ccr>;
// // };

// TEST(test, stuct_T)
// {
//   // inst_xxx_t<> // NOTE 有没有类似指派初始化的方法?
// }

// struct base_t
// {
// };

// struct : base_t
// {
//   int a;
// } op_decs;

// TEST(test, unnamed)
// {
//   IC(op_decs.a);
// }

// template <typename T, bool ByteAligned = true>
// struct slot_decs
// {
//   using datatype = T;
//   const static bool byte_aligned = ByteAligned;
//   size_t bits_offset;
//   size_t total_bits;
//   size_t elem_size;
// };

// struct slot_desc_t
// {
// };

// struct __gnne_add_slot_t : slot_desc_t
// {
//   struct _src1
//   {
//     /* data region */
//     size_t bytes;
//     std::vector<size_t> shape;
//     /* slot region */
//     constexpr static auto bytes_slot = std::make_tuple(
//         slot_decs<uint32_t, true>{416, 32, 1},
//         slot_decs<uint32_t, true>{896, 32, 1});

//     constexpr static auto shape_slot = std::make_tuple(
//         slot_decs<uint32_t, true>{704, 32, 4},
//         slot_decs<uint16_t, false>{2371, 16, 4});
//   } src1{};

//   struct _src2
//   {

//     size_t bytes;
//     std::vector<size_t> shape;

//     constexpr static auto bytes_slot = std::make_tuple(
//         slot_decs<uint32_t, true>{352, 32, 1},
//         slot_decs<uint32_t, true>{640, 32, 1});
//     constexpr static auto shape_slot = std::make_tuple(
//         slot_decs<uint32_t, true>{960, 32, 4});
//   } src2{};
// } gnne_add_slot{};

// TEST(test, inner_struct)
// {
//   __gnne_add_slot_t add_desc{};
//   IC(add_desc.src2.shape_slot);
//   IC(add_desc.src1.bytes);
// }

// // 这种多态没有太大的意义,并且如果是虚继承的多态,我必须要在虚类中存储所有的变量类型才行.
// void write_slot(slot_desc_t *p)
// {
//   auto dp = static_cast<__gnne_add_slot_t *>(p);
//   IC(dp->src1.bytes);
// }

// TEST(test, dynamic_point)
// {
//   write_slot(&gnne_add_slot);
// }

struct range_t
{
  size_t begin;
  size_t end;

  template <typename T>
  range_t(T a)
      : begin(0), end(a)
  {
  }

  template <typename T>
  range_t(T a, T b)
      : begin(a), end(b)
  {
  }
};

struct slot_decs
{
  size_t bits_offset;
  size_t total_bits;
  range_t range;
};

struct __inputs
{

  uint32_t bytes;
  const static inline auto bytes_slot = std::make_tuple(
      slot_decs{352, 32, 1});

} inputs{};

TEST(test, buid)
{
  // const slot_decs a{1, 2, 3};
}