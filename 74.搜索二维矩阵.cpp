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
    int l = 0, r = h, mid;
    while (l < r) {
      mid = (l + r) / 2;
      if (matrix[mid][x] == target) {
        return true;
      } else if (matrix[mid][x] > target) {
        r = mid;
      } else if (matrix[mid][x] < target) {
        l = mid + 1;
      }
    }
    if (r == h) { return false; }
    y = r, l = 0, r = w;
    while (l < r) {
      mid = (l + r) / 2;
      if (matrix[y][mid] == target) {
        return true;
      } else if (matrix[y][mid] > target) {
        r = mid;
      } else if (matrix[y][mid] < target) {
        l = mid + 1;
      }
    }
    return false;
  }
};
// @lc code=end
