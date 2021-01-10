/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  vector<string> summaryRanges(vector<int>& nums) {
    int s = 0, e = 0;
    vector<string> res;
    while (e < nums.size()) {
      while (e < nums.size() and (nums[s] + (e - s)) == nums[e]) {
        e++;
      }
      if (e == s + 1) {
        res.push_back(to_string(nums[s]));
      } else {
        res.push_back(to_string(nums[s]) + "->" + to_string(nums[e - 1]));
      }
      s = e;
    }
    return res;
  }
};
// @lc code=end
