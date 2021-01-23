/*
 * @lc app=leetcode.cn id=470 lang=cpp
 *
 * [470] 用 Rand7() 实现 Rand10()
 */
#include "commom.hpp"
// @lc code=start
// The rand7() API is already defined for you.
int rand7();
// @return a random integer in the range 1 to 7

class Solution {
 public:
  int rand10() {
    /* 先利用一个数字控制奇偶为1/2概率，然后控制返回为1-5 还是 （1-5）+5 */
    int a = rand7(), b = rand7();
    while (a == 7) {
      /* 控制a在 1-6之间，这样奇数和偶数是等概率的 */
      a = rand7();
    }
    while (b > 5) {
      b = rand7();
    }
    if (a % 2) {
      return b;
    }
    return b + 5;
  }
};
// @lc code=end
