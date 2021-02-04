/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int maxProfit(int k, vector<int>& prices) {
    // ! k次买入，0为持有，1为不持有
    vector<vector<int>> dp(k, vector<int>(2, 0));
    if (prices.empty()) {
      return 0;
    }
    if (not k) {
      return 0;
    }
    dp[0][0] = 0 - prices[0];
    for (int i = 1; i < k; i++) {
      dp[i][0] = INT_MIN;
    }
    for (int i = 0; i < prices.size(); i++) {
      for (int j = 0; j < k; j++) {
        int selled = (j == 0 ? 0 : dp[j - 1][1]);
        // clang-format off
        tie(dp[j][0], dp[j][1]) =
          make_tuple(
            max(dp[j][0], selled - prices[i]),
            max(dp[j][1], dp[j][0] + prices[i]));
        // clang-format on
      }
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
      ans = max(ans, dp[i][1]);
    }
    return ans;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Vec<int> nums{2, 4, 1};
  Solution s;
  ic(s.maxProfit(2, nums));
  return 0;
}
