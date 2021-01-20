/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  int ans;

 public:
  int maximumProduct(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    auto p = nums.rbegin();
    int ans2 = (*p) * (*(p + 1)) * (*(p + 2));
    int ans3 = nums[0] * nums[1] * (*p);
    return max({nums[0] * nums[1] * nums[2], ans2, ans3});
    // 233
  }

  // void dfs(vector<int>& nums, int pos, int mul) {
  //   if (pos == 3) {
  //     ans = max(ans, mul);
  //     return;
  //   }
  //   for (size_t i = pos; i < nums.size(); i++) {
  //     if (i > 0 and nums[i - 1] == nums[i]) {
  //       continue;  // 去重
  //     }

  //     dfs(nums, i + 1, mul * nums[i]);
  //   }
  // }
};
// @lc code=end
