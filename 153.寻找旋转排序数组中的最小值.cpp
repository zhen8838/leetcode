/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int findMin(vector<int>& nums) {
    int l = 0, r = nums.size() - 1, mid;
    while (l < r) {
      mid = l + r >> 1;
      if (nums[mid] <= nums[r]) r = mid;
      else l = mid + 1;
    }
    return nums[l];
  }
};
// @lc code=end
int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums{2, 4, 5, 6, 7, 0, 1};
  ic(s.findMin(nums));
  return 0;
}
