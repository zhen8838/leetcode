/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int minDistance(string word1, string word2) {
    int h = word1.size(), w = word2.size();
    vector<vector<int>> dp(h + 1, vector<int>(w + 1, 0));
    for (int y = 1; y <= h; y++) { dp[y][0] = y; }
    for (int x = 1; x <= w; x++) { dp[0][x] = x; }
    for (int y = 1; y <= h; y++) {
      for (int x = 1; x <= w; x++) {
        if (word1[y - 1] == word2[x - 1]) {
          dp[y][x] = dp[y - 1][x - 1];
        } else {
          dp[y][x] = 1 + min({dp[y - 1][x - 1],  // 替换当前元素即可
                              dp[y - 1][x],      // 添加
                              dp[y][x - 1]});
        }
      }
    }
    return dp[h][w];
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  string w1 = "horse", w2 = "ros";
  Solution s;
  ic(s.minDistance(w1, w2));
  return 0;
}
