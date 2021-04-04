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
    /* 二分两次，
      比如[5,7,7,8,8,10], target = 8，
      */
    if (nums.empty()) return {-1, -1};
    // 我们首先找到大于等于8的左端点（模板1）
    int l = 0, r = nums.size() - 1, mid;
    while (l < r) {
      mid = l + r >> 1;
      if (nums[mid] >= target) r = mid;
      else
        l = mid + 1;
    }
    if (nums[l] != target) return {-1, -1};
    // 然后在新的区域内找到小于等于8的右端点（模板二）
    int start = l;
    r = nums.size() - 1;
    while (l < r) {
      mid = l + r + 1 >> 1;
      if (nums[mid] <= target) l = mid;
      else
        r = mid - 1;
    }
    return {start, l};
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums{1};
  IC(s.searchRange(nums, 1));
  return 0;
}
