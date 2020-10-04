/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

#include "commom.hpp"

// @lc code=start
class Solution {
 public:
  void rotate(vector<vector<int>> &matrix) {
    // 先对称翻转，然后垂直翻转。
    int n = matrix.size();
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < n - i - 1; j++) {
        swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
        // cout << matrix[i][j] << ' ';
      }
      // cout << endl;
    }
    for (size_t i = 0; i < (n / 2); i++) {
      swap(matrix[i], matrix[n - i - 1]);
    }
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  vector<vector<int>> input = {
    {5, 1, 9, 11},
    {2, 4, 8, 10},
    {13, 3, 6, 7},
    {15, 14, 12, 16},
  };

  auto s = Solution();
  s.rotate(input);
  for (auto &&line : input) {
    for (auto &&n : line) {
      cout << n << ' ';
    }
    cout << endl;
  }
  return 0;
}
