/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int l, r;
    for (l = 0, r = 0; r < nums.size(); r++) {
      if (r > 0 and nums[r - 1] == nums[r]) { continue; }
      nums[l++] = nums[r];
    }
    return l;
  }
};
// @lc code=end
