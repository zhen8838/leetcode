/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int hammingWeight(uint32_t n) {
    n = n >> 1;
    n = n >> 1;
    printf("%x\n", n);
    return 0;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  auto s = Solution();
  uint32_t n = 11;
  pscalr(s.hammingWeight(n));

  return 0;
}
