/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */
#include <numeric>

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    // 选择元素和相等,即和为整个数组的一半,如果是奇数,那么就没有
    if (nums.size() < 2) {
      return false;
    }
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2) {
      return false;
    }

    int maxNum = *max_element(nums.begin(), nums.end());
    int target = sum / 2;
    if (maxNum > target) {
      return false;
    }
    vector<vector<bool>> dp(nums.size(), vector<bool>(target + 1, false));
    dp[0][nums[0]] = true;
    for (int i = 1; i < nums.size(); i++) {
      for (int j = 0; j < target + 1; j++) {
        if (j == 0) {
          dp[i][j] = true;  //任何数都不选,必定为0.所以必存在这个情况
        } else {
          // 对于同一个target,如果之前的元素就能满足,那么现在肯定也满足,同时如果子集满足去除当前元素的值,也算满足
          if (j > nums[i]) {
            dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]];
          } else {
            dp[i][j] = dp[i - 1][j];
          }
        }
      }
    }
    return dp[nums.size() - 1][target];
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums{99, 1};
  s.canPartition(nums);
  return 0;
}
