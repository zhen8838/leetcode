/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int buy1 = -prices[0], sell1 = 0, buy2 = INT_MIN, sell2 = 0;
    /*
    ! 4种状态，均定义为最大收益
    ? 1.  第一次持有的最大收益
      * 保持不变
      * 昨天卖出了今天买入
    ? 2.  第一次卖出的最大收益
      * 保持不变
      * 昨天持有今天卖出
    ? 3.  第二次持有的最大收益
      * 保持不变
      * 第一次卖出后，今天持有
    ? 4.  第二次卖出的最大收益
      * 保持不变
      * 第二次持有后，今天卖出
    ! 注意，有时候买卖一次的收益比买卖两次高，所以返回结果需要对比一下。比如 [1,2,3,4,5]，买卖一次收益为4，买卖两次收益为3.
     */
    for (int i = 1; i < prices.size(); i++) {
      // clang-format off
      tie(buy1, sell1, buy2, sell2) = make_tuple(
        max(buy1, 0-prices[i]),
        max(sell1, buy1+prices[i]),
        max(buy2, sell1-prices[i]),
        max(sell2, buy2+prices[i]));
      // clang-format on
    }
    return max(sell1, sell2);
  }
};
// @lc code=end
int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> prices{1, 2, 3, 4, 5};
  ic(s.maxProfit(prices));
  return 0;
}
