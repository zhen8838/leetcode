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
    int c = 0;
    bool carry = false;
    uint mask = 1;
    for (int i = 1; i <= 32; i++) {
      if ((a & mask) and (b & mask)) {  // 两个1
        if (carry) {                    // 有进位且1+1又进位
          c |= mask;
        } else {  // 没进位,但 1+1得0 进位；
          carry = true;
        }
      } else if ((a & mask) or (b & mask)) {  // 一个0一个1
        if (carry) {                          // 有进位+1得0 ，继续进位
          carry = true;
        } else {
          c |= mask;
        }
      } else {        // 两个0
        if (carry) {  // 有进位，加1，
          c |= mask;
          carry = false;
        }
      }
      mask <<= 1;
    }
    return c;
  }
  int getSum2(int a, int b) {
    // a 与 b为0，那么就是全部错位的，异或能得到正确结果
    uint c = 0;
    while (b != 0) {
      c = (uint)(a & b) << 1;
      a ^= b;
      b = c;
    }

    // return c;
    return a;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  int a = -12, b = -8;
  Solution s;
  ic(s.getSum(a, b));
  ic(s.getSum2(a, b));
  ic(bitset<32>(-20));
  ic(bitset<4>(3 ^ 3), bitset<4>((3 & 3) << 1));
  return 0;
}
