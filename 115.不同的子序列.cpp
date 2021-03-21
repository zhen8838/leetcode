/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int numDistinct(string s, string t) {
    int w = s.size(), h = t.size();
    if (w < h) { return 0; }
    vector<vector<long>> dp(h + 1, vector<long>(w + 1, 0));
    for (int x = 0; x <= w; x++) { dp[0][x] = 1; }
    for (int y = 1; y <= h; y++) {
      for (int x = y; x <= w; x++) {
        dp[y][x] = dp[y][x - 1] + (s[x - 1] == t[y - 1] ? dp[y - 1][x - 1] : 0);
      }
    }
    return dp[h][w];
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  ic(s.numDistinct("rabbbit", "rabbit"));
  return 0;
}
