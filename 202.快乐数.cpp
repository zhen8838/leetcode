/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool isHappy(int n) {
    map<int, int> d;
    d[n]++;
    int t, next;
    while (n != 1) {
      next = 0;
      while (n) {
        t = n % 10;
        n -= t;
        n /= 10;
        next += t*t;
      }
      // ic(next);
      n = next;
      d[n]++;
      if (d[n] > 1) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  ic(s.isHappy(19));
  return 0;
}
