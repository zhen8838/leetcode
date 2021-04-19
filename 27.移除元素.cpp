/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    if (nums.empty()) { return 0; }
    int i = 0, j = nums.size() - 1;
    while (i < j) {
      if (nums[i] == val) {
        while (i < j and nums[j] == val) { j--; }
        if (i == j) { break; }
        swap(nums[i], nums[j]);
      }
      i++;
    }
    while (i < nums.size() and nums[i] != val) { i++; }
    return i;
  }
};
// @lc code=end
