/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int maxArea(vector<int>& height) {
    int l = 0, r = height.size() - 1;
    int ans = 0;
    // 想到了双指针,就是tm没想到要从两端开始收缩
    while (l < r) {
      int cur = (r - l) * min(height[r], height[l]);
      if (height[l] < height[r]) {
        l++;
      } else if (height[l] >= height[r]) {
        r--;
      }
      ans = max(ans, cur);
    }
    return ans;
  }
};
// @lc code=end
