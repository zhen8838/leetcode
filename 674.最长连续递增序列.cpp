/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int findLengthOfLCIS(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }
    int ans = 1;
    vector<int> dp(nums.size(), 1);
    for (size_t i = 1; i < nums.size(); i++) {
      if (nums[i - 1] < nums[i]) {
        dp[i] += dp[i - 1];
      }
      // ic(dp);
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{1, 3, 5, 7};
  Solution s;
  s.findLengthOfLCIS(nums);
  return 0;
}
