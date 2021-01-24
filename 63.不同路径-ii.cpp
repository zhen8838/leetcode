/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int h = obstacleGrid.size(), w = obstacleGrid[0].size();
    vector<vector<int>> dp(h, vector<int>(w, 0));
    if (obstacleGrid[0][0] == 1) {
      return 0;
    }

    for (size_t y = 0; y < h; y++) {
      for (size_t x = 0; x < w; x++) {
        if (obstacleGrid[y][x] == 0) {
          if (y == 0 and x == 0) {
            dp[y][x] = 1;
          } else {
            int up = y > 0 ? dp[y - 1][x] : 0, left = x > 0 ? dp[y][x - 1] : 0;
            dp[y][x] = up + left;
          }
        }
      }
    }
    return dp[h - 1][w - 1];
  }
};
// @lc code=end
