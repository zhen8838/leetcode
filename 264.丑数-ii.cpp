/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int nthUglyNumber(int n) {
    vector<int> dp(n, 0);
    dp[0] = 1;
    int pa = 0, pb = 0, pc = 0;
    int a = 0, b = 0, c = 0;
    for (int i = 1; i < n; i++) {
      a = dp[pa] * 2, b = dp[pb] * 3, c = dp[pc] * 5;
      dp[i] = min({a, b, c});
      // 一定要三个if防止重复
      if (dp[i] == a) {
        pa++;
      }
      if (dp[i] == b) {
        pb++;
      }
      if (dp[i] == c) {
        pc++;
      }
    }
    return dp.back();
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  ic(s.nthUglyNumber(10));
  return 0;
}
