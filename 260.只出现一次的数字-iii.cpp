/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  vector<int> singleNumber(vector<int>& nums) {
    long a = 0;
    for (auto&& num : nums) {
      a ^= num;
    }
    uint diff = a & (-a);  // 得到x和y异或中第一个不同的位置。
    // 以这个位置为分界线，将数组分为两组
    long b = 0;
    a = 0;
    for (auto&& num : nums) {
      // 这里一定是==0，因为差异位不一定在第几位，用0最方便判断。
      if ((num & diff) == 0) {
        a ^= num;
      } else {
        b ^= num;
      }
    }
    return {(int)a, (int)b};
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Vec<int> nums{1, 1, 0, -2147483648};
  Solution s;
  ic(s.singleNumber(nums));
  return 0;
}
