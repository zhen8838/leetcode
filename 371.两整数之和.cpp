/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int getSum(int a, int b) {
    uint carry;
    while (b) {
      carry = (a & b); 
      carry <<= 1;  // 两个都是1,那么进一位,同时用uint保证不溢出
      a = (a ^ b);
      b = carry;
    }
    return a;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  int a = -1, b = 3;

  ic(bitset<32>(a), bitset<32>(b), bitset<32>(a + b), bitset<32>(a | b));
  int c = 0b11111111111111111111111111111111;
  ic(c, bitset<32>(1), bitset<32>(~(-1) + 1));
  ic(INT_MIN, bitset<32>(0x100000000), bitset<32>(INT_MIN),
     bitset<32>(~INT_MIN + 1), bitset<32>(INT_MIN + 5), INT_MIN + 5);
  a = 0x100000000;
  b = INT_MIN;
  ic(a == b);
  return 0;
}
