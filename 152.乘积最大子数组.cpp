/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    int maxF = 1, minF = 1, ans = INT_MIN, mn, mx;
    for (size_t i = 0; i < nums.size(); i++) {
      mx = maxF;
      mn = minF;  // must use temp var
      maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
      minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
      // ic(i, maxF, minF);
      ans = max(ans, maxF);
    }
    return ans;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{-4, -3, -2};
  Solution s;
  ic(s.maxProduct(nums));
  return 0;
}
