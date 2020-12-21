/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  vector<vector<int>> res;

 public:
  vector<vector<int>> permute(vector<int>& nums) {
    backtrack(nums, 0, nums.size());
    return res;
  }

  void backtrack(vector<int>& nums, int first, int len) {
    if (first == len) {
      res.push_back(nums);
      return;
    }
    for (size_t i = first; i < len; i++) {
      swap(nums[i], nums[first]);
      backtrack(nums, first + 1, len);
      swap(nums[i], nums[first]);
    }
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {1, 2, 3};
  auto res = s.permute(nums);
  IC(res);
  return 0;
}
