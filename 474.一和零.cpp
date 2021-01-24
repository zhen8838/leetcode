/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> cnt(strs.size(), vector<int>(2, 0));
    for (int i = 0; i < strs.size(); i++) {
      for (auto&& c : strs[i]) {
        if (c == '0') {
          cnt[i][0]++;
        } else {
          cnt[i][1]++;
        }
      }
    }

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (auto&& c : cnt) {
      // 一定要从大到小更新,如果从小到大更新每次都需要循环考虑每个子集
      int cm = c[0], cn = c[1];
      for (int i = m; i >= 0; i--) {
        for (int j = n; j >= 0; j--) {
          if (i - cm >= 0 and j - cn >= 0) {
            dp[i][j] = max(1 + dp[i - cm][j - cn], dp[i][j]);
          }
        }
      }
    }

    return dp[m][n];
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<string> ss{"10", "0001", "111001", "1", "0"};
  ic(s.findMaxForm(ss, 3, 4));
  return 0;
}
