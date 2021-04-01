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
    if (x == 1) { return 1; }
    int l = 0, r = x, mid;
    long long t;
    int ans;
    while (l <= r) {
      mid = (l + r) / 2;
      t = (long long)mid * mid;
      if (t == x) {
        return mid;
      } else if (t < x) {
        ans = mid;
        l = mid + 1;
      } else if (t > x) {
        r = mid - 1;
      }
    }
    return ans;
  }
};
// @lc code=end
int main(int argc, char const* argv[]) {
  Solution s;
  ic(s.mySqrt(3));
  return 0;
}
