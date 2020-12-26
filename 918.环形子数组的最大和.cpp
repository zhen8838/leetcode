/*
 * @lc app=leetcode.cn id=918 lang=cpp
 *
 * [918] 环形子数组的最大和
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int maxSubarraySumCircular(vector<int>& A) {
    int n = A.size(), idx, ans = INT_MIN;
    vector<int> dp(A.size() * 2, INT_MIN);
    for (size_t i = 0; i < n * 2; i++) {
      if (i >= n) {
        idx = i - n;
        dp[i] = max(nums[idx], nums[idx] + dp[i]);
      } else {
        dp[i] = max(nums[idx], nums[idx] + dp[i]);
      }

      ans = max(ans, dp[i]);
    }
    return ans;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) { return 0; }
