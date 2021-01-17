/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    for (size_t i = 1; i < triangle.size(); i++) {
      for (size_t j = 0; j < triangle[i].size(); j++) {
        int l = j - 1, r = j;
        if (0 <= l and r < triangle[i - 1].size()) {
          triangle[i][j] = triangle[i][j] + min(triangle[i - 1][l], triangle[i - 1][r]);
        } else if (l < 0) {
          triangle[i][j] = triangle[i][j] + triangle[i - 1][r];
        } else {
          triangle[i][j] = triangle[i][j] + triangle[i - 1][l];
        }
      }
    }
    int ans = triangle.back()[0];
    for (size_t i = 1; i < triangle.back().size(); i++) {
      ans = min(ans, triangle.back()[i]);
    }

    return ans;
  }
};
// @lc code=end
