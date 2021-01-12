/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int ans = 0;
    for (size_t y = 0; y < matrix.size(); y++) {
      for (size_t x = 0; x < matrix[y].size(); x++) {
        if (matrix[y][x] != '0') {
          if (x > 0 and y > 0) {
            matrix[y][x] =
                min(min(matrix[y - 1][x] - '0', matrix[y][x - 1] - '0'),
                    matrix[y - 1][x - 1] - '0') +
                '1';
          }
          ans = max(ans, matrix[y][x] - '0');
        }
        // ic(matrix);
      }
      // ic(matrix);
    }
    return ans * ans;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Mat<char> matrix{
      Vec<char>{'1', '0', '1', '0', '0'}, Vec<char>{'1', '0', '1', '1', '1'},
      Vec<char>{'1', '1', '1', '1', '1'}, Vec<char>{'1', '0', '0', '1', '0'}};
  Solution s;
  ic(s.maximalSquare(matrix));
  return 0;
}
