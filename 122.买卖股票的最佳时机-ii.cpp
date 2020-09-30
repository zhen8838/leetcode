/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include "commom.hpp"

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int> &prices) {
    auto buy = -1;
    auto profit = 0;
    bool first_buy = true;
    if (prices.size() > 1) {
      for (size_t i = 0; i < prices.size() - 1; i++) {
        if (buy != -1 and buy < prices[i]) {
          profit += prices[i] - buy;
          buy = -1;
        }
        if (prices[i] < prices[i + 1]) {
          buy = prices[i];
        }
        // cout << prices[i] << " " << prices[i + 1] << " " << profit << " " << buy << endl;
      }
      if (buy != -1 and buy < prices.back()) {
        profit += prices.back() - buy;
        buy = -1;
      }
    }
    return profit;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  vector<int> i = {1, 2, 3, 4, 5};
  auto s = Solution();
  auto profit = s.maxProfit(i);
  cout << profit << endl;
  return 0;
}
/*   删除排序数组中的重复项
     买卖股票的最佳时机 II
     旋转数组
     存在重复元素
     只出现一次的数字
     两个数组的交集 II
     加一
     移动零
     两数之和
     有效的数独
     旋转图像 */