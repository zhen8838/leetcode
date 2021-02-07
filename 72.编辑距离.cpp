/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
 public:
  int minDistance(string word1, string word2) {
    int h = word1.size(), w = word2.size();
    vector<vector<int>> dp(h + 1, vector<int>(w + 1, 0));
    for (int y = 0; y <= h; y++) {
      dp[y][0] = y;
    }
    for (int x = 0; x <= h; x++) {
      dp[0][x] = x;
    }

    for (int y = 1; y <= h; y++) {
      for (int x = 1; x <= w; x++) {
        if (word1[y] == word2[x]) {
          dp[y][x] = dp[y - 1][x - 1];
        } else {
          
        }
      }
    }
  }
};
// @lc code=end
