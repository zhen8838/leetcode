/*
 * @lc app=leetcode.cn id=440 lang=cpp
 *
 * [440] 字典序的第K小数字
 */
#include "commom.hpp"
// @lc code=start
// struct cmp {
//   bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
//     if (a.second == b.second) {
//       return a < b;
//     }
//     int am = a.second, bm = b.second, va = a.first, vb = b.first;
//     while (am != bm) {
//       if (am > bm) {
//         vb *= 10;
//         bm++;
//       } else {
//         va *= 10;
//         am++;
//       }
//     }
//     if (va == vb) {
//       return a.second < b.second;
//     }
//     return va < vb;
//   };
// };
class Solution {
 private:
 public:
  int findKthNumber(int n, int k) {
    int pre = 1;
    while (k != 1) {
      int steps = getsteps(pre, n);
      if (k > steps) {
        k -= steps;
        pre += 1;
      } else {
        steps /= 10;
        pre *= 10;
        k -= 1;
      }
    }
    return pre;
  }
  int getsteps(long pre, long n) {
    long cur = pre;
    long next = pre + 1;
    long step = 0;
    while (cur <= n) {
      step += min(next, n + 1) - cur;
      cur *= 10;
      next *= 10;
    }
    return step;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  ic(s.findKthNumber(10, 2));
  // ic(s.getlen(1));
  return 0;
}
