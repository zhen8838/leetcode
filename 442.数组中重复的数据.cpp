/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */

// @lc code=start
class Solution {
 public:
  vector<int> findDuplicates(vector<int>& nums) {
    vector<int> out;
    for (size_t i = 0; i < nums.size(); i++) {
      // 去看一眼对应的索引的值,如果是正的就转负,如果是负的那么就重复了
      if (nums[abs(nums[i]) - 1] > 0) {
        nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
      } else {
        out.push_back(abs(nums[i]));
      }
    }
    return out;
  }
};
// @lc code=end
