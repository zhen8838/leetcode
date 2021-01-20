/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  vector<vector<string>> ans;

 public:
  vector<vector<string>> partition(string s) {
    int n = s.size();
    vector<vector<bool>> dp(s.size(), vector<bool>(n, false));
    for (size_t step = 0; step < n; step++) {
      for (size_t i = 0; i < n - step; i++) {
        size_t j = i + step;
        if (step == 0) {
          dp[i][j] = true;
        } else if (step == 1) {
          if (s[i] == s[j]) {
            dp[i][j] = true;
          }
        } else {
          dp[i][j] = (s[i] == s[j]) and (dp[i + 1][j - 1]) ? true : false;
        }
      }
    }
    // ic(dp);
    vector<string> track;
    dfs(s, dp, track, 0, n);
    return ans;
  }
  void dfs(string& s, vector<vector<bool>>& dp, vector<string>& track, int i,
           int n) {
    if (i == n) {
      ans.push_back(track);
      return;
    }

    for (size_t j = 0; j < n; j++) {
      if (dp[i][j]) {
        track.push_back(s.substr(i, j - i + 1));
        dfs(s, dp, track, j + 1, n);
        track.pop_back();
      }
    }
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  string s = "aba";
  Solution S;
  ic(S.partition(s));
  return 0;
}
