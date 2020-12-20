/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  string longestPalindrome(string s) {
    string res;
    for (size_t i = 0; i < s.length(); i++) {
      string s1 = found(s, i, i);
      string s2 = found(s, i, i + 1);
      res = res.length() > s1.length() ? res : s1;
      res = res.length() > s2.length() ? res : s2;
    }
    return res;
  }
  string found(string& s, int l, int r) {
    while (l >= 0 && r <= s.length() && s[l] == s[r]) {
      l--;
      r++;
    };
    return s.substr(l + 1, r - l - 1);
  }
  string dplongestPalindrome(string s) {
    /* dp 还是会超时 */
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    string ans = "";
    for (size_t l = 0; l < n; l++) {
      for (size_t i = 0; i + l < n; i++) {
        int j = i + l;
        if (l == 0) {
          dp[i][j] = true;  // 终结条件
        } else if (l == 1) {
          dp[i][j] = (s[i] == s[j]);  // 终结条件
        } else {
          // 状态转移
          dp[i][j] = (dp[i + 1][j - 1]) & (s[i] == s[j]);
        }
        // 更新参数
        if (dp[i][j] && l + 1 > ans.length()) {
          ans = s.substr(i, l + 1);
        }
      }
    }
    return ans;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  IC(s.longestPalindrome("babad"));
  return 0;
}
