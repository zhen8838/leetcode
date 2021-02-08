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
    word1.insert(word1.begin(), ' ');
    word2.insert(word2.begin(), ' ');
    vector<vector<int>> dp(h + 1, vector<int>(w + 1, 0));
    for (int y = 1; y <= h; y++) {
      dp[y][0] = y;
    }
    for (int x = 1; x <= w; x++) {
      dp[0][x] = x;
    }

    /*
    * dp[y][x] 表示 word1[:y] 修改为word2[:x] 的最大编辑距离。

    *1. 修改: aa->ab = a->a + 1。
      * dp[y][x]=dp[y-1][x-1]+1;

    *2. 添加: aa->ab = a->ab + 1。
      * dp[y][x]=dp[y-1][x]+1;

    *3. 删除: aa->ab = aa->a + 1。
      * dp[y][x]=dp[y][x-1]+1;

    ! 当s1[y]==s2[x]时不需要操作

    */
    for (int y = 1; y <= h; y++) {
      for (int x = 1; x <= w; x++) {
        if (word1[y] == word2[x]) {
          dp[y][x] = dp[y - 1][x - 1];
        } else {
          // clang-format off
          dp[y][x] = min({
            dp[y - 1][x - 1],
            dp[y - 1][x],
            dp[y][x - 1]}) + 1;
          // clang-format on
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
