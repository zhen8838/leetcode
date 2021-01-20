/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int integerBreak(int n) {
    vector<int> dp(n + 1, 0);

    if (n > 3) {
      dp[2] = 2;
      dp[3] = 3;
      for (size_t i = 4; i < n + 1; i++) {
        int cur = 0;
        for (size_t j = 2; j <= i / 2; j++) {
          // 还得是双循环才行.
          cur = max(cur, dp[j] * dp[i - j]);
        }
        dp[i] = cur;
      }
    } else {
      if (n == 2) {
        return 1;
      }
      if (n == 3) {
        return 2;
      }
    }
    return dp.back();
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  ic(s.integerBreak(5));
  return 0;
}
