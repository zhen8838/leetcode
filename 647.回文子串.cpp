/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int countSubstrings(string s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    int cnt = 0;
    for (size_t i = 0; i < s.size(); i++) {
      dp[i][i] = 1;
      cnt++;
    }
    for (size_t k = 1; k < s.size(); k++) {
      for (size_t i = 0; i < s.size() - k; i++) {
        int j = i + k;
        if (k < 2) {
          if (s[i] == s[j]) {
            dp[i][j] = 1;
            cnt++;
          }
        } else {
          if (s[i] == s[j] and dp[i + 1][j - 1]) {
            dp[i][j] = 1;
            cnt++;
          }
        }
      }
    }
    // ic(dp);
    return cnt;
  }
};
// @lc code=end

int main(int argc, char const *argv[])
{
  string s="abccba";
  Solution S;
  ic(S.countSubstrings(s));

  return 0;
}
