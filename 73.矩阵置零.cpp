/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    // 这里可以用set去优化空间为m+n
    auto cols = vector<int>(), rows = vector<int>();
    for (size_t i = 0; i < matrix.size(); i++) {
      for (size_t j = 0; j < matrix[i].size(); j++) {
        if (matrix[i][j] == 0) {
          rows.push_back(i);
          cols.push_back(j);
        }
      }
    }
    for (auto&& row : rows) {
      fill(matrix[row].begin(), matrix[row].end(), 0);
    }
    for (auto&& col : cols) {
      for (size_t i = 0; i < matrix.size(); i++) {
        matrix[i][col] = 0;
      }
    }
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  auto s = Solution();
  auto mat = vector<vector<int>>({
      vector<int>({0, 1, 2, 0}),
      vector<int>({3, 4, 5, 2}),
      vector<int>({1, 3, 1, 5}),
  });
  s.setZeroes(mat);
  for (auto&& row : mat) {
    IC(row);
  }

  return 0;
}
