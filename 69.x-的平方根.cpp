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
    if (x == 1) {
      return 1;
    }

    int left = 0, right = x / 2 + 1;
    long t, mid;
    while (left < right) {
      mid = (left + right) / 2;
      // ic(mid, left, right);
      t = mid * mid;
      if (t == x) {
        // right = mid;
        return mid;
      } else if (t < x) {
        left = mid + 1;
      } else if (t > x) {
        right = mid;
      }
    }
    if (t > x) {
      return mid - 1;
    }
    return mid;
  }
};
// @lc code=end
int main(int argc, char const* argv[]) {
  Solution s;
  ic(s.mySqrt(4));
  return 0;
}
