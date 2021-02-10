/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size(), mid;
    while (l < r) {
      mid = (l + r) / 2;
      if (target == nums[mid]) {
        return mid;
      } else if (target < nums[mid]) {
        r = mid;
      } else if (target > nums[mid]) {
        l = mid + 1;
      }
    }
    return l;
  }
};
// @lc code=end
int main(int argc, char const* argv[]) {
  Vec<int> nums{1, 3};
  Solution s;
  ic(s.searchInsert(nums, 2));
  return 0;
}
