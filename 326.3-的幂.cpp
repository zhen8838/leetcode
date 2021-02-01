/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 */

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool isPowerOfThree(int n) { return n > 0 and (1162261467 % n) == 0; }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  auto s = Solution();
  ic(s.isPowerOfThree(12));
  ic(s.isPowerOfThree(-9));
  return 0;
}
