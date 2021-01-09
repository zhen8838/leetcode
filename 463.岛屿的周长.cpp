/*
 * @lc app=leetcode.cn id=463 lang=cpp
 *
 * [463] 岛屿的周长
 */
#include "commom.hpp"

// @lc code=start
class Solution {
 public:
  int islandPerimeter(vector<vector<int>>& grid) {
    int h = grid.size(), w = grid[0].size();
    for (size_t y = 0; y < h; y++) {
      for (size_t x = 0; x < w; x++) {
        if (grid[y][x] == 1) {
          return dfs(grid, x, y, w, h);
        }
      }
    }
    return 0;
  }

  int dfs(vector<vector<int>>& grid, int x, int y, int w, int h) {
    if (isout(x, y, w, h)) {
      return 1;
    }
    // ic(y, x,grid[y][x]);
    if (grid[y][x] == 0) {
      return 1;
    }
    if (grid[y][x] == -1) {
      return 0;
    }
    grid[y][x] = -1;
    int res = (dfs(grid, x + 1, y, w, h) + dfs(grid, x, y + 1, w, h) +
               dfs(grid, x - 1, y, w, h) + dfs(grid, x, y - 1, w, h));
    return res;
  }

  bool isout(int x, int y, int w, int h) {
    if (0 <= x and x < w and 0 <= y and y < h) {
      return false;
    }
    return true;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<int>> mat{{1, 1}, {1, 1}};
  ic(s.islandPerimeter(mat));
  return 0;
}
