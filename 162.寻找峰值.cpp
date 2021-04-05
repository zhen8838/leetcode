/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int findPeakElement(vector<int>& nums) {
    int n = nums.size(), l = 0, r = n - 1, mid;
    while (l < r) {
      mid = (l + r + 1) >> 1;
      if ((mid > 0 and nums[mid] > nums[mid - 1]) or
          (mid == 0 and nums[mid] > nums[mid + 1]))
        l = mid;
      else
        r = mid - 1;
    }
    return l;
  };
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{1, 2, 3, 1};
  Solution s;
  IC(s.findPeakElement(nums));
  return 0;
}
