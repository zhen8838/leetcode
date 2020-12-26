/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */
#include "commom.hpp"
// @lc code=start
class NumArray {
 private:
  vector<int> nums;
  vector<vector<int>> dp;

 public:
  NumArray(vector<int>& nums) {
    this->nums = nums;
    int n = nums.size();
    for (size_t i = 0; i < n; i++) {
      dp.push_back(vector<int>(n - i, nums[i]));
      for (size_t j = 1; j < n - i; j++) {
        // ic(dp[i][j], i, j);
        dp[i][j] = dp[i][j - 1] + nums[i + j];
      }
    }
  }

  int sumRange(int i, int j) { return dp[i][j - i]; }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end
int main(int argc, char const* argv[]) {
  vector<int> nums{-2, 0, 3, -5, 2, -1};
  // vector<vector<int>> nums{{-2, 0, 3, -5}, {2, -1}};
  // nums.push_back(vector<int>(4,-1));
  NumArray arr(nums);
  ic(arr.sumRange(0, 2));
  ic(arr.sumRange(2, 5));
  ic(arr.sumRange(0, 5));
  return 0;
}
