/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1, mid;
    while (l <= r) {
      mid = (l + r) / 2;
      // ic(l, mid, r, nums[l], nums[mid], nums[r]);
      if (nums[mid] == target) {
        return true;
      }
      if (nums[l] == nums[mid]) {
        l++;  // 避免重复
        continue;
      }

      /* 先看前面是不是有序 */
      if (nums[l] < nums[mid]) {
        /* 前面是有序的，那么检测当前target在有序部分 */
        if (nums[l] <= target and target < nums[mid]) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      } else {
        /* 后面是有序的，这里需要检查target是不是在有序部分 */
        if (nums[mid] < target and target <= nums[r]) {
          l = mid + 1;
        } else {
          r = mid - 1;
        }
      }
    }
    return false;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{2, 5, 6, 0, 0, 1, 2};
  Solution s;
  ic(s.search(nums, 6));
  return 0;
}
