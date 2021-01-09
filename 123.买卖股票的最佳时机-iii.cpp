/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */
#include "commom.hpp"
// @lc code=start
class Solution {
  //  private:
  //   int ans = 0;

 public:
  int maxProfit(vector<int>& prices) {
    vector<int> dp(4, 0);
    if (prices.size() < 2) {
      return 0;
    }

    dp[0] = -prices[0];
    dp[1] = 0;
    dp[2] = -prices[0];
    dp[3] = 0;
    for (size_t i = 1; i < prices.size(); i++) {
      dp[0] = max(-prices[i], dp[0]);
      dp[1] = max(dp[0] + prices[i], dp[1]);
      dp[2] = max(dp[1] - prices[i], dp[2]);
      dp[3] = max(dp[2] + prices[i], dp[3]);
    }
    return dp[3];
  }
};
// @lc code=end
int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> prices{3, 3, 5, 0, 0, 3, 1, 4};
  ic(s.maxProfit(prices));
  return 0;
}
