/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int divide(int dividend, int divisor) {
    bool flag = true;
    if (divisor > 0) {
      divisor = -divisor;
      flag = !flag;
    }
    if (dividend > 0) {
      dividend = -dividend;
      flag = !flag;
    }
    int res = div(dividend, divisor);
    if (res == INT_MIN) {
      res = flag ? INT_MAX : res;
    } else {
      res = flag ? res : -res;
    }
    return res;
  }

  int div(int a, int b) {
    if (a > b) {
      return 0;
    }

    int old_b = b, bb = b;
    uint t = 1, tt = 1;
    // set uint t to avoid tt overflow
    while (a <= bb and bb > -1073741824) {
      // set bb > -1073741824 to avoid  bb overflow
      t = tt;
      tt += tt;
      b = bb;
      bb += bb;
    }
    return t + div(a - b, old_b);
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  ic(s.divide(-2147483648, -1));
  ic(s.divide(10, -3));
  ic(s.divide(-2147483648, 1));
  // int a = 2147483647;
  // ic(a, -a, a + a, -2147483648 / -1);
  return 0;
}
