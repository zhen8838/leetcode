/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
 public:
  int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1, mid;
    while (l < r) {
      if (nums[l] == nums[r]) {
        l++;
        continue;
      }
      mid = l + r >> 1;
      if (nums[mid] <= nums[r]) r = mid;
      else
        l = mid + 1;
    }
    return nums[l];
  }
};
// @lc code=end
