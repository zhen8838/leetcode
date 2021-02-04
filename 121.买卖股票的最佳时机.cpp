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
    /*
     ! 每天的收益情况有两种:
     * 当天买入了股票，那么我们就是要找负的最大值。

     * 当天卖出了股票，也就是收益，那么我们将历史最大收益和今天卖出的收益进行比较。

    */

    int buy = -prices[0], sell = 0, ans = 0;
    for (int i = 1; i < prices.size(); i++) {
      tie(buy, sell) =
          make_tuple(max(buy, -prices[i]), max(sell, buy + prices[i]));
    }
    return sell;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  // s.maxProfit();
  return 0;
}
