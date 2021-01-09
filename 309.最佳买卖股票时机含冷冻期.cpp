/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */
#include "commom.hpp"

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) {
      return 0;
    }
    vector<vector<int>> dp(3, vector<int>(2, 0));
    /*
      不持有:
        1.  卖出前一天持有的,并进入冻结期
        2.  继续不持有
      持有:
        1.  两天前卖出,今天买入
        2.  继续持有
    */
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    dp[1][0] = max(dp[0][1] + prices[1], dp[0][0]);
    dp[1][1] = max(-prices[1], dp[0][1]);  // 第一天没买,今天买入.或者继续持有
    for (size_t i = 2; i < prices.size(); i++) {
      dp[2][0] = max(dp[1][1] + prices[i], dp[1][0]);
      dp[2][1] = max(dp[0][0] - prices[i], dp[1][1]);
      dp[0][0] = dp[1][0];
      dp[0][1] = dp[1][1];
      dp[1][0] = dp[2][0];
      dp[1][1] = dp[2][1];
    }
    return dp[min(prices.size() - 1, (size_t)2)][0];
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> p{1, 2, 4};
  s.maxProfit(p);
  return 0;
}
