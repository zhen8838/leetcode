/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int hammingDistance(int x, int y) {
    int n = x xor y;
    int cnt = 0;
    while (n != 0) {
      cnt++;
      n = n & (n - 1);
    }
    return cnt;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  auto s = Solution();
  uint32_t x = 0b00000000000000000000000000000001;
  uint32_t y = 0b00000000000000000000000000000100;
  pscalr(s.hammingDistance(x, y));

  return 0;
}
