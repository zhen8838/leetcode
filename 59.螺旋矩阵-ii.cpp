/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> mat(n, vector<int>(n));
    int cnt = 1, num = n * n;
    int xs = 0, ys = 0, h = n, w = n;
    while (num >= cnt) {
      if (w - xs == 1) {
        mat[ys][xs] = cnt++;
      }
      for (int x = xs; num >= cnt and x < w - 1; x++) {
        mat[ys][x] = cnt++;
      }
      // ic(mat);
      for (int y = ys; num >= cnt and y < h - 1; y++) {
        mat[y][w - 1] = cnt++;
      }
      // ic(mat);
      for (int x = w - 1; num >= cnt and x > xs; x--) {
        mat[h - 1][x] = cnt++;
      }
      for (int y = h - 1; num >= cnt and y > ys; y--) {
        mat[y][xs] = cnt++;
      }
      // ic(mat);
      // break;
      xs++;
      ys++;
      h--;
      w--;
    }
    return mat;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  int n = 1;
  Solution s;
  ic(s.generateMatrix(n));
  return 0;
}
