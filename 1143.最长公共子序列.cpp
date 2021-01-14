/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int longestCommonSubsequence(string text1, string text2) {
    int h = text1.size(), w = text2.size();
    vector<vector<int>> dp(h, vector<int>(w, 0));
    for (size_t y = 0; y < h; y++) {
      for (size_t x = 0; x < w; x++) {
        if (text1[y] == text2[x]) {
          int ul = (y > 0 and x > 0) ? dp[y - 1][x - 1] : 0;
          dp[y][x] = ul + 1;
        } else {
          int up = y > 0 ? dp[y - 1][x] : 0;
          int left = x > 0 ? dp[y][x - 1] : 0;
          dp[y][x] = max(up, left);
        }
      }
      // ic(dp);
    }
    return dp[h - 1][w - 1];
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  string a = "bsbininm", b = "jmjkbkjkv";
  s.longestCommonSubsequence(a, b);
  return 0;
}
