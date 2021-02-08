/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  // int firstMissingPositive1(vector<int>& nums) {
  //   int n = nums.size();
  //   vector<int> dp(301, 1);
  //   for (int i = 0; i < n; i++) {
  //     if (0 < nums[i] and nums[i] < 300) {
  //       dp[nums[i]] = 0;
  //     }
  //   }
  //   for (int i = 1; i < 301; i++) {
  //     if (dp[i] == 1) {
  //       return i;
  //     }
  //   }
  //   return 301;
  // }
  int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    while (i < n) {
      int j = nums[i];
      if (1 <= j and j <= n           // 消除不合适的元素
          and (j - 1) != i            // 把1放到0的位置
          and nums[i] != nums[j - 1]  // 避免[1,1]这样的陷入死循环
      ) {
        swap(nums[i], nums[j - 1]);
      } else {
        i++;
      }
    }
    for (int i = 0; i < n; i++) {
      if (nums[i] != (i + 1)) {
        return i + 1;
      }
    }
    return n + 1;
  }
};
// @lc code=end
int main(int argc, char const* argv[]) {
  Solution s;
  Vec<int> nums{1, 2, 0};
  ic(s.firstMissingPositive(nums));
  return 0;
}
