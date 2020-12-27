/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int uniquePaths(int m, int n) {
    if (m == 1 or n == 1) {
      return 1;
    }
    vector<vector<int>> mat(m, vector<int>(n, 0));
    int x, y, right, down;
    mat[m - 1][n - 1] = 1;
    for (int i = n - 2; i >= -(m - 1); i--) {
      for (int j = max(0 - i, 0); j < min(n - i, m); j++) {
        x = i + j, y = m - 1 - j;
        right = x + 1 == n ? 0 : mat[y][x + 1];
        down = y + 1 == m ? 0 : mat[y + 1][x];
        mat[y][x] = right + down;
        // ic(mat);
      }
    }

    return mat[0][0];
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  ic(s.uniquePaths(7, 3));
  return 0;
}
