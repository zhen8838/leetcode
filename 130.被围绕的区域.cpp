/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  int h, w;

 public:
  void solve(vector<vector<char>>& board) {
    h = board.size();
    if (h == 0) {
      return;
    }
    w = board[0].size();
    if (w == 0) {
      return;
    }

    for (size_t y = 0; y < h - 0; y++) {
      for (size_t x = 0; x < w - 0; x++) {
        if (y == 0 or x == 0 or y == h - 1 or x == w - 1) {
          if (board[y][x] == 'O') {
            dfs(board, x, y, 'O', '#');
          }
        }
      }
    }
    for (size_t y = 1; y < h - 1; y++) {
      for (size_t x = 1; x < w - 1; x++) {
        if (board[y][x] == 'O') {
          dfs(board, x, y, 'O', 'X');
        }
      }
    }
    for (size_t y = 0; y < h - 0; y++) {
      for (size_t x = 0; x < w - 0; x++) {
        if (y == 0 or x == 0 or y == h - 1 or x == w - 1) {
          if (board[y][x] == '#') {
            dfs(board, x, y, '#', 'O');
          }
        }
      }
    }
  }
  void dfs(vector<vector<char>>& board, int x, int y, char src, char dest) {
    if (not isvalid(x, y)) {
      return;
    }
    if (board[y][x] != src) {
      return;
    }
    board[y][x] = '?';
    dfs(board, x - 1, y, src, dest);
    dfs(board, x, y - 1, src, dest);
    dfs(board, x + 1, y, src, dest);
    dfs(board, x, y + 1, src, dest);
    board[y][x] = dest;
  }
  bool isvalid(int x, int y) {
    if (0 <= x and x < w and 0 <= y and y < h) {
      return true;
    }
    return false;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  Mat<char> grid{{'O', 'X', 'X', 'O', 'X'},
                 {'X', 'O', 'O', 'X', 'O'},
                 {'X', 'O', 'X', 'O', 'X'},
                 {'O', 'X', 'O', 'O', 'O'},
                 {'X', 'X', 'O', 'X', 'O'}};
  s.solve(grid);
  ic(grid);
  return 0;
}
