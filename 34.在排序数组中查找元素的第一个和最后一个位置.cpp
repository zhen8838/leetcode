/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res(2, -1);
    if (nums.empty()) {
      return res;
    }
    size_t left = 0, right = nums.size();
    while (left < right) {
      size_t mid = (left + right) / 2;
      // ic(left, mid, right, nums[mid]);
      if (nums[mid] == target) {
        right = mid;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else if (nums[mid] > target) {
        // right has one more element
        right = mid;
      }
    }
    if (left == nums.size()) {
      return res;
    }
    if (nums[left] == target) {
      res[0] = left;
      while (left < nums.size() and nums[left] == target) {
        left++;
      }
      res[1] = left - 1;
    }

    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums{1};
  IC(s.searchRange(nums, 1));
  return 0;
}
