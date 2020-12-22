/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  int h, w;

 public:
  bool exist(vector<vector<char>>& board, string word) {
    h = board.size();
    w = board[0].size();
    for (size_t x = 0; x < w; x++) {
      for (size_t y = 0; y < h; y++) {
        // IC(dfs(board, word, 0, x, y), x, y);
        if (dfs(board, word, 0, x, y)) {
          return true;
        }
      }
    }
    return false;
  }

  bool dfs(vector<vector<char>>& board, string& word, int i, int x, int y) {
    if (not isvalid(x, y)) {
      return false;
    }
    // IC(board[y][x], word[i], i);
    if (board[y][x] == word[i]) {
      if (i == (word.length() - 1)) {
        return true;
      } else {
        // 同一个单元格内的字母不能被重复使用，因此进入下一层的时候需要mask当前元素
        board[y][x] = '#';
        bool res = (dfs(board, word, i + 1, x + 1, y) ||
                    dfs(board, word, i + 1, x - 1, y) ||
                    dfs(board, word, i + 1, x, y + 1) ||
                    dfs(board, word, i + 1, x, y - 1));
        board[y][x] = word[i];  // 恢复当前元素
        return res;
      }
    } else {
      return false;
    }
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
  vector<vector<char>> board = {
      {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  string word = "SEE";
  Solution s;

  IC(s.exist(board, word));

  return 0;
}
