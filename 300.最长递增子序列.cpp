/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> dp(nums.size(), 1);
    if (nums.size() < 2) {
      return nums.size();
    }
    int maxans = 0;
    for (size_t i = 1; i < nums.size(); i++) {
      for (size_t j = 0; j < i; j++) {
        // 每个位置都与前面那个位置的数进行比较,如果大于那个数,那么加上当前数我们的子序列就可以加1,当然这种情况有很多种,所以我们要加个max,取最大的那种取法.
        if (nums[i] > nums[j]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      maxans = max(dp[i], maxans);
      // ic(dp);
    }
    return maxans;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{1, 3, 6, 7, 9, 4, 10, 5, 6};
  Solution s;
  ic(s.lengthOfLIS(nums));
  return 0;
}
