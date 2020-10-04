/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

#include "commom.hpp"

// @lc code=start
class Solution {
 public:
  void moveZeroes(vector<int> &nums) {
    // NOTE 此方法较慢
    // int zero_cnt = 0, len = nums.size();
    // for (size_t i = 0; i < (len - zero_cnt); i++) {
    //   while (nums[i] == 0 && zero_cnt < len) {
    //     nums.erase(nums.begin() + i);
    //     nums.push_back(0);
    //     zero_cnt++;
    //   }
    // }
    // 双指针一次遍历
    int j = 0;
    // 用j标记零元素，用非0元素和0元素互换保证顺序
    for (size_t i = 0; i < nums.size(); i++) {
      if (nums[i] != 0) {
        swap(nums[i], nums[j++]);
      }
    }
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  vector<int> input = {0};
  auto s = Solution();
  s.moveZeroes(input);
  for (auto &&i : input) {
    cout << i << ", ";
  }
  cout << endl;
  return 0;
}
