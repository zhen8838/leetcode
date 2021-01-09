/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int ans = 0, n = prices.size();
    if (n == 0) {
      return 0;
    }

    vector<vector<int>> dp(n, vector<int>(2, 0));
    /* 0是今天不持股状态下的金额数,
          0.0 之前持有,今天卖出
          0.1 之前也不持有,保持不变
       1是今天持股状态下的金额数
          1.0 之前不持有,今天买入
          1.1 之前持有,保持不变
       */
    dp[0][0] = 0;           //第一天不持有,总金额为0
    dp[0][1] = -prices[0];  //第一天持有,总金额为负的第一天
    for (size_t i = 1; i < n; i++) {
      dp[i][0] = max(dp[i - 1][1] + prices[i], dp[i - 1][0]);
      // 因为只能卖出之后才能买入,那么今天买入的情况就是-prices[i]
      dp[i][1] = max(-prices[i], dp[i - 1][1]);
    }
    return dp[n - 1][0];
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  // s.maxProfit();
  return 0;
}
