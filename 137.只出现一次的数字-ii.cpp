/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    // int ones = 0, twos = 0;
    // for (auto&& num : nums) {
    //   ones = (ones ^ num) & ~twos;
    //   twos = (twos ^ num) & ~ones;
    // }
    // return ones;
    int x = 0, y = 0, t;
    for (auto&& z : nums) {
      t = ~x & (y ^ z);
      x = (x & (~y) & (~z)) | ((~x) & y & z);
      y = t;
      // ic(x, y);
    }
    return y;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Vec<int> nums = {0, 1, 0, 1, 0, 1, 99};
  Solution s;
  ic(s.singleNumber(nums));
  return 0;
}
