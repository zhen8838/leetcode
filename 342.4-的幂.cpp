/*
 * @lc app=leetcode.cn id=342 lang=cpp
 *
 * [342] 4的幂
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool isPowerOfFour(int n) {
    // int offset = 0, i;
    // while (n > 0 and offset <= 15) {
    //   // ic(1 << (offset * 2));
    //   i = 1 << (offset * 2);
    //   if (n == i) {
    //     return true;
    //   } else if (n < i) {
    //     break;
    //   }
    //   offset++;
    // }
    // return false;
    return (n > 0) and ((n & (-n)) == n) and (n % 3 == 1);
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  ic(s.isPowerOfFour(16));
  ic((16 & -16));
  // bitset<32> a(16);
  ic(bitset<32>(    16), bitset<32>(16 - 1));
  return 0;
}
