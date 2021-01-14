/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    if (nums.size() == 3) {
      return nums[0] + nums[1] + nums[2];
    }
    /* 先排序,然后固定一个c, 从左边开始找left,从右边找right */
    sort(nums.begin(), nums.end(), less<int>());

    int ans, best = INT_MAX;
    for (size_t a = 0; a < nums.size(); a++) {
      int l = a + 1, r = nums.size() - 1;
      while (l < r) {
        int cur = nums[a] + nums[l] + nums[r];
        int diff = cur - target;
        if (best > abs(diff)) {
          best = abs(diff);
          ans = cur;
        }
        if (diff == 0) {
          return target;
        } else if (diff < 0) {
          l++;
        } else if (diff > 0) {
          r--;
        }
      }
    }
    return ans;
  }
};
// @lc code=end
