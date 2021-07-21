/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2的幂
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool isPowerOfTwo(int n) {
    // 负数以补码的形式表示
    // 因此 n & (-n-1) == 0
    // 所以咋n & -n
    // 恰好是添加了1，经过进位他正好停留在最后一个1的位置，所以可以来判断有多少个1,如果是2的幂就会停留在原位
    return n > 0 and ((n & -n) == n);
  }
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
