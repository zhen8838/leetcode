/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    // vector<int> dp(nums.size(), 0);
    // dp[0] = nums[0];
    // int maxans;
    // for (size_t i = 1; i < nums.size(); i++) {
    //   dp[i] = max(dp[i - 1], dp[i - 1] + nums[i]);
    //   maxans = max(maxans, dp[i]);
    //   ic(maxans, dp);
    // }
    // return dp[0];
    int pre = 0, maxans = nums[0];
    for (size_t i = 0; i < nums.size(); i++) {
      pre = max(pre + nums[i], nums[i]);
      maxans = max(maxans, pre);
      ic(pre, maxans);
    }
    return maxans;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
  Solution s;
  s.maxSubArray(nums);
  return 0;
}
