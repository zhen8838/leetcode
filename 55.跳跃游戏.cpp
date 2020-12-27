/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool canJump1(vector<int>& nums) {
    int i = 0, big_idx, steps;
    while (i < nums.size() - 1) {
      big_idx = 0;
      steps = 0;
      for (size_t j = 1; j < nums[i] + 1; j++) {
        // ic(i, i + j,nums.size());
        if ((i + j) >= (nums.size() - 1)) {
          return true;
        }

        if (((i + j) + nums[i + j]) >= steps) {
          steps = ((i + j) + nums[i + j]);
          big_idx = j;
        }
      }
      // ic(i, i + big_idx);
      if (nums[i + big_idx] == 0) {
        return false;
      }

      i += big_idx;
    }
    return true;
  }
  bool canJump(vector<int>& nums) {
    // dp , each state is index i highest range.
    int h = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (i > h) {
        return false;
      }
      h = max(i + nums[i], h);
      if (h >= nums.size() - 1) {
        return true;
      }
    }
    return true;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{1, 1, 2, 2, 0, 1, 1};
  Solution s;
  ic(s.canJump(nums));
  return 0;
}
