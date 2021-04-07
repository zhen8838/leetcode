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
    int n = nums.size(), l = 0, r = n - 1, mid;
    // 恢复二段性，通过删除r恢复左边区域的二段性。
    while (l < r and nums[0] == nums[r]) r--;
    while (l < r) {
      mid = l + r + 1 >> 1;
      if (nums[mid] >= nums[0]) l = mid;
      else r = mid - 1;
    }

    if (target >= nums[0] and target <= nums[l]) r = l, l = 0;
    else l = l + 1, r = n - 1;

    while (l < r) {
      mid = l + r >> 1;
      if (nums[mid] >= target) r = mid;
      else l = mid + 1;
    }
    return (l<nums.size() and nums[l] == target) ? true : false;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{1};
  Solution s;
  ic(s.search(nums, 3));
  return 0;
}
