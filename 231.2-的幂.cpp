/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool isPowerOfTwo(int n) { return n > 0 and ((n & -n) == n); }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  int a = 5;
  ic(bitset<32>(a));
  ic(bitset<32>(-a));
  ic(bitset<32>(a & -a));
  ic(7 % 2);
  return 0;
}
