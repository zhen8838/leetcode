/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int l = 0, r = 0, cnt = 0, last;
    while (r < nums.size()) {
      if (cnt == 0) {
        last = nums[r];
      } else if (cnt == 1 and last != nums[r]) {
        cnt = 0;
        last = nums[r];
      } else if (cnt > 1) {
        while (r < nums.size() and last == nums[r]) { r++; }
        if (r == nums.size()) {
          break;
        } else {
          cnt = 0;
          last = nums[r];
        }
      }
      nums[l++] = nums[r++];
      cnt++;
    }
    return l;
  }
};
// @lc code=end
