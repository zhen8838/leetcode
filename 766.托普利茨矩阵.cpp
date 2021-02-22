/*
 * @lc app=leetcode.cn id=766 lang=cpp
 *
 * [766] 托普利茨矩阵
 */

// @lc code=start
class Solution {
 public:
  bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int h = matrix.size(), w = matrix[0].size(), x, y;
    for (int sx = 1, sy = 1; sx < w; sx++) {
      x = sx, y = sy;
      while (0 <= x and x < w and 0 <= y and y < h) {
        if (matrix[y - 1][x - 1] != matrix[y++][x++]) return false;
      }
    }
    for (int sx = 1, sy = 2; sy < h; sy++) {
      x = sx, y = sy;
      while (0 <= x and x < w and 0 <= y and y < h) {
        if (matrix[y - 1][x - 1] != matrix[y++][x++]) return false;
      }
    }
    return true;
  }
};
// @lc code=end
