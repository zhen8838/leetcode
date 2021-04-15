/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  int maxans = 0;

 public:
  int rob(vector<int>& nums) {
    // 今天偷与不偷的最大值
    vector<int> dp(2, 0);
    for (int i = 0; i < nums.size(); i++) {
      tie(dp[0], dp[1]) = make_tuple(dp[1] + nums[i], max(dp[0], dp[1]));
    }
    return max(dp[0], dp[1]);
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{2, 7, 9, 3, 1};
  Solution s;
  ic(s.rob(nums));
  return 0;
}
