/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    if (nums.size() == 0 or nums.size() == 1) {
      return;
    }
    int i = nums.size() - 2;
    /* 首先找到一个非降序对,如果都是降序排列,那么就是最大排列情况,直接reverse即可
     */
    while (i >= 0 and nums[i] >= nums[i + 1]) {
      i--;
    }
    if (i >= 0) {
      int j = nums.size() - 1;
      /* 找到最靠右边的第一个较大数 */
      while (j >= 0 and nums[i] >= nums[j]) {
        j--;
      }
      swap(nums[i], nums[j]);
    }
    reverse(nums.begin() + i + 1, nums.end());
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums{1, 2, 3};
  s.nextPermutation(nums);
  ic(nums);
  return 0;
}
