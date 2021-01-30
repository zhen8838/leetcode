/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() == 1) {
      return nums[0];
    }

    /* 两种情况，从[0,n-1] [1,n] */
    int a_1, b_1, a_2, b_2;
    for (size_t i = 0; i < nums.size(); i++) {
      /* 情况1 */
      if (i < nums.size() - 1) {
        if (i == 0) {
          a_1 = nums[i];
          b_1 = 0;
        } else {
          int a_1_bak = a_1, b_1_bak = b_1;
          a_1 = b_1_bak + nums[i];
          b_1 = max(a_1_bak, b_1_bak);
        }
      }
      /* 情况2 */
      if (i > 0) {
        if (i == 1) {
          a_2 = nums[i];
          b_2 = 0;
        } else {
          int a_2_bak = a_2, b_2_bak = b_2;
          a_2 = b_2_bak + nums[i];
          b_2 = max(a_2_bak, b_2_bak);
        }
      }
    }
    return max(max(a_1, b_1), max(a_2, b_2));
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Vec<int> nums{2, 3, 2};
  Solution s;
  ic(s.rob(nums));
  return 0;
}
