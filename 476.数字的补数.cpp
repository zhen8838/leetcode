/*
 * @lc app=leetcode.cn id=476 lang=cpp
 *
 * [476] 数字的补数
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int findComplement(int num) {
    int n = num;
    uint mask = 0xFFFFFFFF;
    while ((n & mask) != 0) {
      mask <<= 1;
    }
    return (~mask) & (~num);
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  int a = s.findComplement(5);
  ic(bitset<32>(5));
  ic(bitset<32>(~5));
  ic(bitset<32>(a));

  return 0;
}
