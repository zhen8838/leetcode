#include "isa.h"
#include "commom.hpp"
#include <gtest/gtest.h>

using namespace nncase::runtime::k510::isa;
// constexpr value_compare
// OPCODE opcode : 8;
// uint64_t mmu_item : 4;
// uint64_t start_bank : 3;
// MMU_CONF_WIDTH width : 2;
// uint64_t start_depth : 14;
// uint64_t depth : 14;

template <size_t... Is>
constexpr size_t sum(std::index_sequence<Is...>)
{
  return (0 + ... + Is);
}

template <uint64_t mmu_item,
          uint64_t start_bank,
          MMU_CONF_WIDTH width,
          uint64_t start_depth,
          uint64_t depth>
struct inst_mmu_conf_warper
{
  using type = std::index_sequence<0x12, mmu_item,
                                   start_bank,
                                   static_cast<uint64_t>(width),
                                   start_depth,
                                   depth>;
  constexpr static auto values = std::index_sequence<0x12, mmu_item,
                                                     start_bank,
                                                     static_cast<uint64_t>(width),
                                                     start_depth,
                                                     depth>{};
  constexpr static auto bitslen = std::index_sequence<8, 4, 3, 2, 14, 14>{};
  constexpr static size_t elem_size() noexcept { return values.size(); }
  constexpr static size_t inst_size() noexcept { return sum(bitslen); }
};

// template <typename... Inst>
// struct bitwriter
// {
//   constexpr static size_t N =
// };

TEST(bitsteam, step1)
{
  constexpr inst_mmu_conf_warper<0x1, 0x2, MMU_CONF_WIDTH_1, 0x3, 0x4> inst_mmu_conf1{};
  constexpr inst_mmu_conf_warper<0x4, 0x3, MMU_CONF_WIDTH_2, 0x1, 0x0> inst_mmu_conf2{};
  constexpr size_t bitslen = inst_mmu_conf1.inst_size();
  IC(bitslen);
  IC(inst_mmu_conf1.inst_size());
  // IC(inst_mmu_conf.size());
  // std::make_index_sequence<>
}