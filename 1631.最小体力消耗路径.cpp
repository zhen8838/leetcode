/*
 * @lc app=leetcode.cn id=1631 lang=cpp
 *
 * [1631] 最小体力消耗路径
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int minimumEffortPath(vector<vector<int>>& heights) {
    int h = heights.size(), w = heights[0].size(), n, x, y, nx, ny;
    vector<vector<int>> dp(h, vector<int>(w, INT_MAX));
    vector<vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    queue<int> q;
    dp[0][0] = 0;
    q.push(0);
    while (not q.empty()) {
      n = q.front(), q.pop();
      y = n / w;
      x = n % w;
      for (auto&& d : dir) {
        ny = y + d[0];
        nx = x + d[1];
        if (0 <= ny and ny < h and 0 <= nx and nx < w) {
          int tmp = max(dp[y][x], abs(heights[ny][nx] - heights[y][x]));// 起点到(ny,nx)的消耗 为 max(此前最大的消耗,当前消耗)
          if (tmp >= dp[ny][nx]) {
            // 如果这条路径比他原来差，跳过
            continue;
          }
          // 更新到(ny,nx)的最小消耗，并继续行走
          dp[ny][nx] = tmp;
          q.push(ny * w + nx);
        }
      }
    }
    return dp[h - 1][w - 1];
  }
};
// @lc code=end
