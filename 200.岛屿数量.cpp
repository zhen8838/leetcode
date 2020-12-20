/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    int h = grid.size();
    if (h == 0) {
      return 0;
    }
    int w = grid[0].size();
    if (w == 0) {
      return 0;
    }
    int cnt = 0;
    for (size_t y = 0; y < h; y++) {
      for (size_t x = 0; x < w; x++) {
        if (grid[y][x] == '1') {
          cnt++;
          dfs(grid, x, y);
        }
      }
    }
    return cnt;
  }

 private:
  void dfs(vector<vector<char>>& grid, int x, int y) {
    if (!inaera(grid, x, y)) {
      return;
    }
    // 看是否是同一个岛屿
    if (grid[y][x] != '1') {
      return;
    }
    // 看是否是已经探索过得区域
    if (grid[y][x] == '#') {
      return;
    }
    // 标记探索过得区域
    grid[y][x] = '#';

    dfs(grid, x - 1, y);
    dfs(grid, x + 1, y);
    dfs(grid, x, y + 1);
    dfs(grid, x, y - 1);
  }

  bool inaera(vector<vector<char>>& grid, int x, int y) {
    if (x < 0 or x >= grid[0].size()) {
      return false;
    }
    if (y < 0 or y >= grid.size()) {
      return false;
    }
    return true;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<vector<char>> grid = {
      vector<char>({'1', '1', '0', '0', '0'}),
      vector<char>({'1', '1', '0', '0', '0'}),
      vector<char>({'0', '0', '1', '0', '0'}),
      vector<char>({'0', '0', '0', '1', '1'}),
  };
  Solution s;
  IC(s.numIslands(grid));
  IC(grid);

  return 0;
}
