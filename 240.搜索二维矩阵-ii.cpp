/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int h = matrix.size(), w = matrix[0].size();
    int x = matrix[0].size() - 1, y = 0;
    // 选择右上角开始寻找，当前值大于target就往下，小于就往左
    // 如果从左下角开始，那么当前值大于target时就不知选择左还是右。
    while (0 <= x and x < w and 0 <= y and y < h) {
      int tmp = matrix[y][x];
      matrix[y][x] = -1;
      // ic(matrix);
      if (target == tmp) {
        return true;
      } else if (target > tmp) {
        y++;
      } else if (target < tmp) {
        x--;
      }
    }

    return false;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<int>> matrix = {{1, 4, 7, 11, 15},
                                {2, 5, 8, 12, 19},
                                {3, 6, 9, 16, 22},
                                {10, 13, 14, 17, 24},
                                {18, 21, 23, 26, 30}};
  ic(s.searchMatrix(matrix, 20));
  return 0;
}
