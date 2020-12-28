/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 0);
    int last;
    for (int i = 1; i < amount + 1; i++) {
      last = INT_MAX;
      for (auto&& coin : coins) {
        if ((i - coin) < 0) {
          last = min(last, INT_MAX);
        } else {
          if (dp[i - coin] != INT_MAX) {
            last = min(last, dp[i - coin] + 1);
          }
        }
      }
      dp[i] = last;
    }
    if (*dp.rbegin() == INT_MAX) {
      return -1;
    }
    return *dp.rbegin();
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums{2};
  ic(s.coinChange(nums, 3));
  return 0;
}
