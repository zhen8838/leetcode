/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size(), mid;
    while (left < right) {
      mid = (left + right) / 2;
      // ic(nums, left, mid, right);
      if (target == nums[mid]) {
        return mid;
      }
      if (target >= nums[0] and nums[mid] < nums[0]) {
        /* 目标值如果大于数组的第一个，那么结果就在前半段
        此时将不符合的结果置位inf，即
        [4,5,6,7,inf,inf,inf]*/
        nums[mid] = INT_MAX;
      } else if (target < nums[0] and nums[mid] > nums[0]) {
        /* 目标值如果小于数组的第一个，那么结果就在后半段
        此时将不符合的结果置位-inf，即
        [-inf,-inf,-inf,-inf,0,1,2]*/
        nums[mid] = INT_MIN;
      }
      // 保持原始的二分查找方式
      if (target > nums[mid]) {
        left = mid + 1;
      } else if (target < nums[mid]) {
        right = mid;
      }
    }
    return -1;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{3, 1};
  Solution s;
  ic(s.search(nums, 1));
  return 0;
}
