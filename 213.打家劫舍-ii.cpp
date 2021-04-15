/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() == 1) { return nums[0]; }
    return max(robsingle(nums, 0, nums.size() - 1),
               robsingle(nums, 1, nums.size()));
  }
  int robsingle(vector<int>& nums, int start, int end) {
    // 今天偷与不偷的最大值
    vector<int> dp(2, 0);
    for (int i = start; i < end; i++) {
      tie(dp[0], dp[1]) = make_tuple(dp[1] + nums[i], max(dp[0], dp[1]));
    }
    return max(dp[0], dp[1]);
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Vec<int> nums{2, 3, 2};
  Solution s;
  ic(s.rob(nums));
  return 0;
}
