/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int rangeBitwiseAnd(int m, int n) {
    int cnt = 0;
    while (m != n) {
      // ic(bitset<10>(m));
      // ic(bitset<10>(n));
      // ic(' ');
      m >>= 1;
      n >>= 1;
      cnt++;
    }
    return m << cnt;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  // for (size_t i = 0; i < 30; i++) {
  //   ic(bitset<10>(i));
  // }
  Solution s;
  ic(s.rangeBitwiseAnd(5, 7));

  return 0;
}
