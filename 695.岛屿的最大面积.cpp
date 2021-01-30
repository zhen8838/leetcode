/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
 private:
  int h, w;

 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    h = grid.size(), w = grid[0].size();
    int ans = 0;
    for (size_t y = 0; y < h; y++) {
      for (size_t x = 0; x < w; x++) {
        if (grid[y][x] == 1) {
          ans = max(ans, dfs(grid, x, y));
        }
      }
    }
    return ans;
  }

  int dfs(vector<vector<int>>& grid, int x, int y) {
    if (not isvalid(x, y)) {
      return 0;
    }
    if (grid[y][x] != 1) {
      return 0;
    }
    grid[y][x] = 2;
    int res = 1 + dfs(grid, x - 1, y) + dfs(grid, x + 1, y) +
              dfs(grid, x, y - 1) + dfs(grid, x, y + 1);
    grid[y][x] = 0;
    return res;
  }
  bool isvalid(int x, int y) { return (0 <= x and x < w and 0 <= y and y < h); }
};
// @lc code=end
