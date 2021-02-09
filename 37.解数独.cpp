/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */
#include <numeric>

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  void solveSudoku(vector<vector<char>>& board) { dfs(board, 0, 0); }
  bool dfs(vector<vector<char>>& board, int y, int x) {
    if (x == 9) return dfs(board, y + 1, 0);
    if (y == 9) return true;
    if (board[y][x] != '.') return dfs(board, y, x + 1);

    for (char c = '1'; c <= '9'; c++) {
      if (canput(board, y, x, c)) {
        board[y][x] = c;
        if (dfs(board, y, x + 1)) break;
        board[y][x] = '.';
      }
    }
    return board[y][x] != '.';
  }
  bool canput(vector<vector<char>>& board, int y, int x, char c) {
    for (int i = 0; i < 9; i++) {
      if (board[y][i] == c) return false;
      if (board[i][x] == c) return false;
      if (board[((y / 3) * 3) + (i / 3)][((x / 3) * 3) + (i % 3)] == c) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  Mat<char> mat{
      {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
      {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
      {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
      {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
      {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
      {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
      {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
      {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
      {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
  };

  s.solveSudoku(mat);
  ic(mat);

  return 0;
}
