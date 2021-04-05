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
    int n = nums.size(), l = 0, r = n - 1, mid;
    while (l < r) {
      mid = l + r >> 1;
      if (nums[mid] <= nums[r]) r = mid;
      else l = mid + 1;
    }

    if (target <= nums[n - 1]) r = n - 1;
    else r = l - 1, l = 0;

    while (l < r) {
      mid = l + r >> 1;
      if (nums[mid] >= target) r = mid;
      else l = mid + 1;
    }
    return nums[l] == target ? l : -1;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{4, 5, 6, 7, 0, 1, 2};
  Solution s;
  ic(s.search(nums, 0));
  return 0;
}
