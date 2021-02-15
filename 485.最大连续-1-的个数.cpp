/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续1的个数
 */

// @lc code=start
class Solution {
 public:
  int findMaxConsecutiveOnes(vector<int>& nums) {
    int ans = 0, last = 0, cur;
    for (auto&& num : nums) {
      if (num == 1) {
        cur = last + 1;
        ans = max(ans, cur);
      } else {
        cur = 0;
      }
      last = cur;
    }
    return ans;
  }
};
// @lc code=end
