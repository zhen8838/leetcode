/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start
class Solution {
  int ans, h, w;

 public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    h = matrix.size(), w = matrix[0].size();
    ans = 0;
    vector<vector<int>> dp(h, vector<int>(w, 1));
    vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (int y = 0; y < h; y++) {
      for (int x = 0; x < w; x++) {
        dfs(matrix, dp, dirs, x, y, 1);
      }
    }
    return ans;
  }
  void dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp,
           vector<pair<int, int>>& dirs, int x, int y, int cnt) {
    if (dp[y][x] > cnt) {
      return;
    }
    dp[y][x] = cnt;
    for (auto&& [dx, dy] : dirs) {
      int nx = x + dx, ny = y + dy;
      if (isvalid(nx, ny) and matrix[y][x] < matrix[ny][nx]) {
        dfs(matrix, dp, dirs, nx, ny, cnt + 1);
      }
    }
    ans = max(ans, cnt);
  }
  bool isvalid(int x, int y) { return 0 <= x and x < w and 0 <= y and y < h; }
};
// @lc code=end
