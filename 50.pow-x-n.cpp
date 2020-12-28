/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  double myPow(double x, int n) {
    bool flag = true;
    long long N = n;
    if (N < 0) {
      return 1 / pow(x, -N);
    } else {
      return pow(x, N);
    }
  }

  double pow(double x, long long n) {
    if (n == 0) {
      return 1.;
    }
    double y = pow(x, n / 2);
    if (n % 2 == 0) {
      return y * y;
    } else {
      return y * y * x;
    }
  }
};
// @lc code=end
