/*
 * @lc app=leetcode.cn id=486 lang=cpp
 *
 * [486] 预测赢家
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool PredictTheWinner(vector<int>& nums) {
    // if (nums.size() == 1) {
    //   return true;
    // }

    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (size_t step = 0; step < n; step++) {
      for (size_t i = 0; i < n - step; i++) {
        size_t j = i + step;
        if (step == 0) {
          // 如果只有一个数,必加
          dp[i][j] = nums[i];
        } else {
          // 当前选择的净胜分,即我选左边i, 那么减去[i+1,j]的最大值
          dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        }
      }
    }
    // ic(dp);
    return dp[0][n - 1] >= 0;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{1, 5, 2};
  Solution s;
  ic(s.PredictTheWinner(nums));
  return 0;
}
