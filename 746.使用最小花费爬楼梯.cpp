/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int minCostClimbingStairs(vector<int>& cost) {
    int dp[3];
    dp[0] = 0;
    dp[1] = min(cost[0], cost[1]);
    if (cost.size() == 2) {
      return dp[1];
    }

    for (size_t i = 2; i < cost.size(); i++) {
      // ic(dp[0] + cost[i], dp[1] + cost[i - 1]);
      dp[2] = min(dp[0] + cost[i - 1], dp[1] + cost[i]);
      dp[0] = dp[1];
      dp[1] = dp[2];
    }
    return dp[2];
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  Solution s;
  ic(s.minCostClimbingStairs(nums));
  return 0;
}
