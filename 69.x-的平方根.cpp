/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int mySqrt(int x) {
    long l = 0, r = x, mid;  //避免溢出
    while (l < r) {
      mid = (l + r + 1) >> 1;
      if (mid <= (x / mid)) l = mid;
      else
        r = mid - 1;
    }
    return l;
  }
};
// @lc code=end
int main(int argc, char const* argv[]) {
  Solution s;
  ic(s.mySqrt(3));
  return 0;
}
