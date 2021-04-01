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
    int l = 0, r = nums.size() - 1, mid;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (target == nums[mid]) {
        return mid;
        // 先判断当前mid的值在逆序的左边还是右边
      } else if (nums[l] <= nums[mid]) {
        if (target < nums[mid] and target >= nums[l]) {
          r = mid;
        } else {
          l = mid + 1;
        }
      } else if (nums[l] > nums[mid]) {
        if (target > nums[mid] and target <= nums[r]) {
          l = mid + 1;
        } else {
          r = mid;
        }
      } else if (l == r) {
        break;
      }
    }
    return -1;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{4, 5, 6, 7, 0, 1, 2};
  Solution s;
  ic(s.search(nums, 0));
  return 0;
}
