/*
 * @lc app=leetcode.cn id=867 lang=cpp
 *
 * [867] 转置矩阵
 */

// @lc code=start
class Solution {
 public:
  vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int h = matrix.size(), w = matrix[0].size();
    vector<vector<int>> res;
    for (int x = 0; x < w; x++) {
      vector<int> row;
      for (int y = 0; y < h; y++) { row.push_back(matrix[y][x]); }
      res.push_back(row);
    }
    return res;
  }
};
// @lc code=end
