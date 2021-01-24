/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int h = matrix.size(), w = matrix[0].size();
    int y = 0, x = w - 1;
    ;
    while (y < h and x >= 0) {
      if (matrix[y][x] > target) {
        x--;
      } else if (matrix[y][x] < target) {
        y++;
      } else {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
