/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

#include "commom.hpp"

// @lc code=start
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    /* 冒泡 */
    // bool swaped = true;
    // int n = nums.size(), last = -1, right = n - 1;
    // while (swaped) {
    //   swaped = false;
    //   for (int i = 0; i < right; i++) {
    //     if (nums[i] == 0) {
    //       swap(nums[i], nums[i + 1]);
    //       swaped = true;
    //       last = i;
    //     }
    //   }
    //   right = last;
    // }
    /* 双指针 */
    int j = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) swap(nums[i], nums[j++]);
    }
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> input = {0};
  auto s = Solution();
  s.moveZeroes(input);
  for (auto&& i : input) { cout << i << ", "; }
  cout << endl;
  return 0;
}
