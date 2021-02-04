/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include "commom.hpp"

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    // * 贪心
    /*     int last = prices[0], sell = 0;
        for (int i = 1; i < prices.size(); i++) {
          if (prices[i] >= last) {
            sell += prices[i] - last;
          }
          last = prices[i];
        }
        return sell; */
    // * dp 状态两种
    // * 1. 今天卖出的最大收益，
    // *** 1.1 昨天持有的加上今天收入的钱。
    // * 2. 今天持有的最大收益，
    // *** 2.1 昨天卖出今天买进
    // *** 2.2 继续持有

    int buy = -prices[0], sell = 0;
    for (int i = 0; i < prices.size(); i++) {
      tie(sell, buy) =
          make_tuple(max(buy + prices[i], sell), max(sell - prices[i], buy));
    }
    return sell;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> i = {1, 2, 3, 4, 5};
  auto s = Solution();
  auto profit = s.maxProfit(i);
  cout << profit << endl;
  return 0;
}