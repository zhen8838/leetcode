/*
 * @lc app=leetcode.cn id=836 lang=cpp
 *
 * [836] 矩形重叠
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
    int x1, y1, x2, y2;
    x1 = max(rec1[0], rec2[0]);
    y1 = max(rec1[1], rec2[1]);
    x2 = min(rec1[2], rec2[2]);
    y2 = min(rec1[3], rec2[3]);
    if (y1 < y2 and x1 < x2) {
      return true;
    }
    return false;
  }
};
// @lc code=end
