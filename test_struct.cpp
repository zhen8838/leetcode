#include "commom.hpp"
#include "gtest/gtest.h"

struct A
{
  std::array<uint8_t, 16> arr;
  uint16_t data;
  uint64_t u64;
};

struct CCRCLR
{
  uint64_t ccr_clr : 1; /** 是否需要将某个 CCR 减 1 **/
  uint64_t ccr : 6;     /** 指明使用哪个 CCR **/
  uint64_t ccr_acq : 1; /** 是否需要等待某个ccr **/
  constexpr CCRCLR(uint64_t value = 0) : ccr_clr(value),
                                         ccr(value),
                                         ccr_acq(value) {}
  constexpr uint64_t value() const noexcept
  {
    return (uint64_t)ccr_clr;
  }
  constexpr operator uint64_t() const noexcept
  {
    return value();
  }
};

// template <typename T>
// struct inst_xxx_t
// {
// };

// template <typename T, typename... Args>
// constexpr const T &emit(Args... args)
// {
//   constexpr T t{args...};
//   return t;
// }

struct inst_xxxx_s
{
  uint16_t data = uint16_t(0);
  uint64_t u64 = uint64_t(0);
  CCRCLR ccr = CCRCLR(0);
};

TEST(test, stuct_A)
{

  inst_xxxx_s s{.data = 10};
  ic(s.u64);

  // auto a = get<A>({{1, 2, 3, 4}, 2, 3});
  // auto b = get<inst_xxxx_s>({1, 2, CCRCL R(0)});
  // constexpr static inst_xxxx_s s{uint16_t(1), uint64_t(2), CCRCLR(0)};

  // auto v = emit<inst_xxxx_s>(uint16_t(1), uint64_t(2), CCRCLR(0));
  // constexpr static inst_xxx_t<inst_xxxx_s{uint16_t(1), uint64_t(2), CCRCLR(0)}>{};
  // inst_xxx_t<get_a<inst_xxxx_s>(uint16_t(1), uint64_t(2), CCRCLR(0))>{};
}

template <uint16_t data = 0,
          uint64_t u64 = 0,
          uint64_t ccr = 0>
struct inst_xxx_t
{
  using type = std::index_sequence<data, u64, ccr>;
};

// template <uint64_t... Values>
// struct inst_xxx_t_v2
// {
//   using type = std::index_sequence<data, u64, ccr>;
// };

TEST(test, stuct_T)
{
  // inst_xxx_t<> // NOTE 有没有类似指派初始化的方法?
}

struct base_t
{
};

struct : base_t
{
  int a;
} op_decs;

TEST(test, unnamed)
{
  IC(op_decs.a);
}
