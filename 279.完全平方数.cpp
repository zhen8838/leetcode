/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int numSquares(int n) {
    int maxn = (int)(sqrt((float)n));
    // int nums
    vector<int> nums;
    for (size_t i = 1; i <= maxn; i++) {
      nums.push_back(i * i);
    }
    vector<int> dp(n + 1, 0);
    for (int i = 1; i < n + 1; i++) {
      int maxv = INT_MAX;
      for (auto&& num : nums) {
        if ((i - num) >= 0) {
          // ic(i,num, dp[i]);
          maxv = min(maxv, dp[i - num]);
        }
      }
      dp[i] = maxv + 1;
      // ic(dp);
    }
    return dp.back();
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  int n = 13;
  Solution s;
  ic(s.numSquares(n));
  return 0;
}
