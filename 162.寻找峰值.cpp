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
    nums.push_back(INT_MIN);
    nums.insert(nums.begin(), INT_MIN);
    for (size_t i = 1; i < nums.size() - 1; i++) {
      if (nums[i - 1] < nums[i] and nums[i] > nums[i + 1]) {
        return i - 1;
      }
    }
    return 0;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{1, 2, 3, 1};
  Solution s;
  IC(s.findPeakElement(nums));
  return 0;
}
