/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */

// @lc code=start
class Solution {
 public:
  bool checkPossibility(vector<int>& nums) {
    if (nums.size() == 1) {
      return true;
    }

    int ll, l, cur, ans = 0;
    for (int i = 0; i < nums.size(); i++) {
      cur = 1;
      if (i > 0 and nums[i] >= nums[i - 1]) {
        cur = l + 1;
      }
      if (i > 1 and nums[i] >= nums[i - 2]) {
        cur = max(cur, ll + 1);
      }
      ans = max(ans, cur);
      ll = l;
      l = cur;
    }
    if (ans >= nums.size() - 1) {
      return true;
    }
    return false;
  }
};
// @lc code=end
