/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (auto&& c : coins) {
      for (int i = 1; i < amount + 1; i++) {
        dp[i] += (i - c) >= 0 ? dp[i - c] : 0;
      }
    }
    return dp[amount];
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums{1, 2, 5};
  ic(s.change(4, nums));
  return 0;
}
