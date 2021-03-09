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
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    for (int step = 0; step < n; step++) {
      for (int i = 0; i < n - step; i++) {
        int j = i + step;
        if (step == 0) {
          dp[i][j] = true;
        } else if (step == 1) {
          dp[i][j] = (s[i] == s[j]);
        } else {
          dp[i][j] = ((s[i] == s[j]) and dp[i + 1][j - 1]);
        }
      }
    }
    vector<string> track;
    dfs(dp, track, s, 0);
    return ans;
  }
  void dfs(vector<vector<bool>>& dp, vector<string>& track, string& s, int i) {
    if (i == s.size()) {
      ans.push_back(track);
      return;
    }
    for (int j = i; j < s.size(); j++) {
      if (dp[i][j]) {
        track.push_back(s.substr(i, j - i + 1));
        dfs(dp, track, s, j + 1);
        track.pop_back();
      }
    }
  }
};
// @lc code=end
int main(int argc, char const* argv[]) {
  Solution s;
  string S = "aab";
  ic(s.partition(S));
  return 0;
}
