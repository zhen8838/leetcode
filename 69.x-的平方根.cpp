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
    /* 首先我们需要找到的根号x的向下取整，
      那么也就是说 [0,m]都满足 m^2 < x
      那么也就是说 [m,x]都满足 m^2 > x
      那就是我们要找的是左边部分的右边界，那么用模板二
     */
    int l = 0, r = x, mid;
    while (l < r) {
      mid = l + (long)r + 1 >> 1;
      if (mid <= x / mid) {
        l = mid;
      } else {
        r = mid - 1;
      }
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
