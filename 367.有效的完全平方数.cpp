/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
 public:
  bool isPerfectSquare(int num) {
    long l = 1, r = num, mid;
    while (l < r) {
      mid = l + r >> 1;
      if (mid >= num / mid) r = mid;
      else l = mid + 1;
    }
    return (l * l == num) ? true : false;
  }
};
// @lc code=end
