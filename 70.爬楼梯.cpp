/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
#include "commom.hpp"
// @lc code=start
class Solution {
  //  private:
  //   int cnt = 0;

 public:
  int climbStairs(int n) {
    // dfs(n);
    vector<int> dp(3);
    dp[0] = 1;
    dp[1] = 2;
    if (n <= 2) {
      return dp[n - 1];
    }

    for (size_t i = 2; i < n; i++) {
      dp[2] = dp[0] + dp[1];
      dp[0] = dp[1];
      dp[1] = dp[2];
    }
    return dp[2];
  }

  // void dfs(int n) {
  //   if (n == 0) {
  //     cnt++;
  //     return;
  //   }
  //   /* do choice */

  //   if (n == 1) {
  //     // if only 1 step, choice step 1
  //     dfs(n - 1);
  //   } else {
  //     // else choice 1 or 2
  //     dfs(n - 1);
  //     dfs(n - 2);
  //   }
  // }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  ic(s.climbStairs(1));
  return 0;
}
