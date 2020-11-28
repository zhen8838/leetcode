/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3的幂
 */

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool isPowerOfThree(int n) {
    long m = 1;
    while (m < n) {
      m = m * 3;
    }
    if (m != n) {
      return false;
    }
    return true;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  auto s = Solution();
  pscalr(s.isPowerOfThree(1162261468));
  return 0;
}
