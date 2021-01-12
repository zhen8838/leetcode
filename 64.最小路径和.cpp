/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int minPathSum(vector<vector<int>>& grid) {
    int h = grid.size(), w = grid[0].size();
    vector<vector<int>> dp(h, vector<int>(w, 0));
    dp[0][0] = grid[0][0];
    for (size_t x = 1; x < w; x++) {
      dp[0][x] = dp[0][x - 1] + grid[0][x];
    }
    for (size_t y = 1; y < h; y++) {
      dp[y][0] = dp[y - 1][0] + grid[y][0];
    }
    for (size_t x = 1; x < w; x++) {
      for (size_t y = 1; y < h; y++) {
        dp[y][x] = grid[y][x] + min(dp[y - 1][x], dp[y][x - 1]);
      }
    }
    return dp[h - 1][w - 1];
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Mat<int> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
  Solution s;
  ic(s.minPathSum(grid));
  return 0;
}
