/*
 * @lc app=leetcode.cn id=1388 lang=cpp
 *
 * [1388] 3n 块披萨
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int maxSizeSlices(vector<int>& slices) {
    int n = slices.size();
    // 在3n上面取n个不相邻的数，存在一种情况同时取第一个和最后一个，由于数组是环形所以不能取，所以分两种情况讨论。
    return max(rob(slices, 0, n - 1, n / 3),
               rob(slices, 1, n, n / 3));
  }

  int rob(vector<int>& slices, int s, int e, int choose) {
    // 把问题转换为了在3n的数组上面，取n个不相邻的数
    vector<vector<int>> dp(e - s + 1, vector<int>(choose + 1, 0));
    for (int i = 1; i < e - s + 1; i++) {
      for (int j = 1; j < choose + 1; j++) {
        dp[i][j] = max(dp[i - 1][j],
                       (i > 1 ? dp[i - 2][j - 1] : 0) + slices[s + (i - 1)]);
      }
    }
    return dp[e - s][choose];
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Vec<int> nums{8, 9, 8, 6, 1, 1};
  Solution s;
  ic(s.maxSizeSlices(nums));
  return 0;
}
