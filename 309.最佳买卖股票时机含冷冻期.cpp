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
    ! 这题和之前的题不一样的是dp数组开3个是依次滚动的，而没有冻结期的dp是在自身上面更新。
      持有:
        1.  两天前卖出,今天买入
        2.  继续持有
      不持有:
        1.  卖出前一天持有的,并进入冻结期
        2.  继续不持有
    */
    dp[0][0] = 0 - prices[0];
    dp[1][0] = max(0 - prices[0], 0 - prices[1]);
    dp[1][1] = max(0, dp[0][0] + prices[1]);
    dp[2][0] = INT_MIN;
    dp[2][1] = dp[1][1];  //冻结期只能保持

    for (int i = 2; i < prices.size(); i++) {
      // clang-format off
      tie(dp[2][0], dp[2][1]) =
          make_tuple(
            max(dp[1][0], dp[0][1] - prices[i]),
            max(dp[1][1],dp[1][0]+prices[i]));
      // clang-format on
      dp[0] = dp[1];
      dp[1] = dp[2];
    }
    return dp[2][1];
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> p{1, 2, 4};
  ic(s.maxProfit(p));
  return 0;
}
