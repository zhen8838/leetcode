/*
 * @lc app=leetcode.cn id=1025 lang=cpp
 *
 * [1025] 除数博弈
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool divisorGame(int N) {
    vector<bool> dp(N + 1, false);
    dp[1] = false;
    dp[2] = true;
    for (size_t i = 3; i < N + 1; i++) {
      bool state = false;
      for (size_t x = 1; x < i; x++) {
        if (i % x == 0) {
          state |= !dp[i - x];
        }
      }
      dp[i] = state;
      // ic(i, dp[i]);
    }
    return dp[N];
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  ic(s.divisorGame(1));
  return 0;
}
