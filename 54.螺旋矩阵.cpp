/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int h = matrix.size(), w = matrix[0].size(), n = h * w;
    int ys = 0, xs = 0;
    vector<int> res;
    res.reserve(n);
    while (res.size() < n) {
      if (w - xs == 1 and h - ys == 1) {
        res.push_back(matrix[ys][xs]);
      } else if (w - xs == 1 and h - ys > 1) {
        for (size_t y = ys; y <= h - 1; y++) {
          res.push_back(matrix[y][w - 1]);
        }
      } else if (w - xs > 1 and h - ys == 1) {
        for (size_t x = xs; x <= w - 1; x++) {
          res.push_back(matrix[ys][x]);
        }
      } else {
        for (size_t x = xs; x <= w - 2; x++) {
          res.push_back(matrix[ys][x]);
        }
        for (size_t y = ys; y <= h - 2; y++) {
          res.push_back(matrix[y][w - 1]);
        }
        for (size_t x = w - 1; x >= xs + 1; x--) {
          res.push_back(matrix[h - 1][x]);
        }
        for (size_t y = h - 1; y >= ys + 1; y--) {
          res.push_back(matrix[y][xs]);
        }
      }
      xs++;
      ys++;
      w--;
      h--;
      // ic(xs, ys, w, h);
    }
    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<int>> mat{{2, 3}};
  ic(s.spiralOrder(mat));
  return 0;
}
