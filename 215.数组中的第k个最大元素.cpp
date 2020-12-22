/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end(), greater<int>());
    // IC(nums);
    // set<int> cnt;
    // int i = 0;
    // while (cnt.size() < k) {
    //   cnt.insert(nums[i]);
    //   i++;
    // }

    return nums[k - 1];
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {3, 2, 1, 5, 6, 4};
  IC(s.findKthLargest(nums, 2));
  return 0;
}
