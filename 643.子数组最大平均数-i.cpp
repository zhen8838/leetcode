/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  double findMaxAverage(vector<int>& nums, int k) {
    int n = nums.size();
    double sums = 0;
    for (int i = 0; i < k; i++) {
      sums += nums[i];
    }
    double ans = sums / k;
    for (int i = k; i < n; i++) {
      sums -= nums[i - k];
      sums += nums[i];
      ans = max(ans, sums / k);
    }
    return ans;
  }
};
// @lc code=end
