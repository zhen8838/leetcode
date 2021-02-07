/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    vector<int> s;
    int ans = 0;
    heights.insert(heights.begin(), 0);
    heights.push_back(0);
    for (int i = 0; i < heights.size(); i++) {
      while (not s.empty() and heights[s.back()] > heights[i]) {
        int cur = s.back();
        s.pop_back();
        /* 因为height前面加入了哨兵，left */
        int left = s.back() + 1;
        int right = i - 1;
        ans = max(ans, heights[cur] * (right - left + 1));
      }
      s.push_back(i);
      // ic(s);
    }
    return ans;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  Vec<int> nums{3, 2, 3};
  ic(s.largestRectangleArea(nums));
  return 0;
}
