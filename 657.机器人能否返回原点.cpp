/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool judgeCircle(string moves) {
    int a = 0, b = 0;
    for (auto&& c : moves) {
      if (c == 'U') {
        a++;
      } else if (c == 'D') {
        a--;
      } else if (c == 'L') {
        b++;
      } else if (c == 'R') {
        b--;
      }
    }
    return (a == 0 and b == 0);
  }
};
// @lc code=end
