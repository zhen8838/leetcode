/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */
#include "commom.hpp"

// @lc code=start
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int res = nums[0];
    // NOTE 异或运算满足结合律，因此可以消除
    // a^a=0
    // 0^a=a
    for (size_t i = 1; i < nums.size(); i++) {
      res ^= nums[i];
    }
    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> i = {4, 1, 2, 1, 2};
  auto s = Solution();
  auto profit = s.singleNumber(i);
  cout << profit << endl;
  return 0;
}