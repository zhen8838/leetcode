/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int trap(vector<int>& height) {
    vector<int> s;
    int res = 0, m, l, dist;

    for (int r = 0; r < height.size(); r++) {
      while (!s.empty() and height[r] >= height[s.back()]) {
        m = s.back(), s.pop_back();
        if (!s.empty()) {
          l = s.back();
          dist = r - l - 1;
          res += dist * (min(height[l], height[r]) - height[m]);
        }
      }
      s.push_back(r);
    }
    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  Vec<int> nums{4, 2, 0, 3, 2, 5};
  ic(s.trap(nums));
  return 0;
}
