#include "amx.h"
#include "commom.hpp"
#include <concepts>
#include <gtest/gtest.h>

template <class T> struct operand {
  uint64_t val;

  inline constexpr uint64_t bind(void *ptr) {
    return val | (((1ull << 57) - 1) & (uint64_t)ptr);
  }

  template <uint64_t OffSet, uint64_t Width>
  inline constexpr T set_field(const uint64_t value) const noexcept {
    constexpr uint64_t clr_mask = ~(((1ull << Width) - 1ull) << OffSet);
    uint64_t value_mask = (value << OffSet);
    return T{(val & clr_mask) | value_mask};
  }
};

struct ldxy : operand<ldxy> {
  /**
   * @brief load multiple register
   * factor = multiple ? 2 : 1
   * factor2 = multiple_means_four ? 2 : 1
   *  so total load factor * factor2 * 64 byte
   */
  constexpr auto multiple() const { return set_field<62, 1>(1); }
  constexpr auto non_consecutive() const { return set_field<61, 1>(1); }
  constexpr auto multiple_means_four() const { return set_field<60, 1>(1); }
  /**
   * @brief choice reg id, 0~5
   */
  constexpr auto register_index(const uint64_t index) const {
    return set_field<56, 3>(index);
  }
};

struct stxy : operand<stxy> {
  /**
   * @brief store (multiple ? 2 : 1) * 64 bytes.
   */
  constexpr auto multiple() const { return set_field<62, 1>(1); }
  /**
   * @brief choice reg id, 0~5
   */
  constexpr auto register_index(const uint64_t index) const {
    return set_field<56, 3>(index);
  }
};

struct ldstz : operand<ldstz> {
  /**
   * @brief load or store (multiple ? 2 : 1) * 64 bytes.
   */
  constexpr auto multiple() const { return set_field<62, 1>(1); }
  /**
   * @brief choice row id, 0 ~ 63
   */
  constexpr auto row_index(const uint64_t index) const {
    return set_field<56, 6>(index);
  }
};

TEST(test_amx, test_ldxy) {
  float a[8 * 16];
  float b[8 * 16];
  for (size_t i = 0; i < 8 * 16; i++) {
    a[i] = (float)i;
  }
  constexpr auto ldop = ldxy{}.multiple().multiple_means_four();
  constexpr auto stop = stxy{}.multiple();
  // clang-format off
  AMX_SET();
  AMX_LDX(ldop.register_index(0).bind(a)); /* a[0:4] => x[0:4] */
  AMX_LDX(ldop.register_index(4).bind(a + 16 * 4));  /* a[4:8] => x[4:8] */
  AMX_STX(stop.register_index(0).bind(b));
  AMX_STX(stop.register_index(2).bind(b + 16 * 2));
  AMX_STX(stop.register_index(4).bind(b + 16 * 4));
  AMX_STX(stop.register_index(6).bind(b + 16 * 6));
  AMX_CLR();
  // clang-format on
  for (size_t i = 0; i < 8 * 16; i++) {
    assert(a[i] == b[i]);
  }
}

TEST(test_amx, test_ldstz) {
  constexpr auto total = 16 * 8 * 8;
  float a[total];
  float b[total];
  float c[total];
  for (size_t i = 0; i < total; i++) {
    a[i] = (float)i;
  }
  constexpr auto ldop = ldstz{}; //.multiple();
  AMX_SET();
  for (size_t i = 0; i < 64; i++) {
    AMX_LDZ(ldop.row_index(i).bind(a + i * 16)); /* a[0:16] => z[_,0:16] */
    AMX_STZ(ldop.row_index(i).bind(b + i * 16));
  }
  for (size_t i = 0; i < 32; i++) {
    AMX_STZ(ldop.multiple().row_index(i * 2).bind(
        c + i * 16 * 2)); /*  z[i:i+2,0:16] => c[i:i+32] */
  }
  AMX_CLR();
  for (size_t i = 0; i < total; i++) {
    assert(a[i] == b[i]);
    assert(a[i] == c[i]);
  }
}