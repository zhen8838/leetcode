/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size(), mid;
    while (l < r) {
      mid = (l + r) / 2;
      if (target == nums[mid]) {
        return mid;
      } else if (target < nums[mid]) {
        r = mid;
      } else if (target > nums[mid]) {
        l = mid + 1;
      }
    }
    return -1;
  }
};
// @lc code=end
