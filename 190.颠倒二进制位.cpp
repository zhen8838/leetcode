/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (size_t i = 0; i < 32; i++) {
      res <<= 1;
      if (n & 1) {
        res += 1;
      }
      n >>= 1;
    }
    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  auto s = Solution();
  uint32_t n = 0b11111111111111111111111111111101;
  pscalr(bitset<32>(s.reverseBits(n)));
  return 0;
}
