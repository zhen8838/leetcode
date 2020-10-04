/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

#include "commom.hpp"

// @lc code=start
class Solution {
 public:
  bool isValidSudoku(vector<vector<char>> &board) {
    map<char, int> dict;
    char c;
    for (size_t i = 0; i < 9; i++) {
      for (size_t j = 0; j < 9; j++) {
        c = board[i][j];
        if (c == '.') {
          continue;
        }
        if (dict[c] == 1) {
          return false;
        }
        dict[c] += 1;
      }
      dict.clear();
    }

    for (size_t i = 0; i < 9; i++) {
      for (size_t j = 0; j < 9; j++) {
        c = board[j][i];
        if (c == '.') {
          continue;
        }
        if (dict[c] == 1) {
          return false;
        }
        dict[c] += 1;
      }
      dict.clear();
    }

    for (size_t i = 0; i < 9; i += 3) {
      for (size_t j = 0; j < 9; j += 3) {
        for (size_t n = 0; n < 3; n++) {
          for (size_t m = 0; m < 3; m++) {
            c = board[i + n][j + m];
            if (c == '.') {
              continue;
            }
            if (dict[c] == 1) {
              return false;
            }
            dict[c] += 1;
          }
        }
        dict.clear();
      }
    }

    return true;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  vector<vector<char>> input = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
  };

  auto s = Solution();
  auto out = s.isValidSudoku(input);
  cout << out << endl;

  return 0;
}
