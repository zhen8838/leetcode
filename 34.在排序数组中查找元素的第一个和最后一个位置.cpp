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
    if (nums.empty()) return {-1, -1};
    /* 我们首先找到大于等于target的下界（模板1） */
    int l = 0, r = nums.size() - 1, mid;
    while (l < r) {
      mid = l + r >> 1;
      if (nums[mid] >= target) r = mid;
      else l = mid + 1;
    }
    if (nums[l] != target) return {-1, -1}; // 如果没有直接退出
    /*  在新的区域内找到小于等于target的上界（模板二） */
    int start = l;
    r = nums.size() - 1;
    while (l < r) {
      mid = l + r + 1 >> 1;
      if (nums[mid] <= target) l = mid;
      else r = mid - 1;
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
