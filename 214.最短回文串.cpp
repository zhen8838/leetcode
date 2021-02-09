/*
 * @lc app=leetcode.cn id=214 lang=cpp
 *
 * [214] 最短回文串
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  string shortestPalindrome(string s) {  // 伪暴力法
    string rev(s.rbegin(), s.rend());
    string tmp = s + '#' + rev;
    int idx = findMaxCommon(tmp);
    rev = rev.substr(0, rev.size() - idx);
    return rev + s;
  }
  string shortestPalindrome1(string s) {
    // 伪暴力法
    int n = s.size(), l = 0, r = n - 1, i, lastright;
    lastright = r;
    while (l < r) {
      if (s[l] == s[r]) {
        l++;
        r--;
      } else {
        l = 0;
        r = --lastright;
      }
    }
    string prefix = s.substr(lastright + 1);
    if (prefix.size()) {
      reverse(prefix.begin(), prefix.end());
    }
    prefix.append(s);
    return prefix;
  }

  int findMaxCommon(const string& pattern) {
    int n = pattern.size();
    vector<int> next(n + 1, 0);
    for (int i = 0, j = next[0] = -1; i < n; next[++i] = ++j) {
      while ((j != -1) and pattern[j] != pattern[i]) {
        j = next[j];
      }
    }
    return next[n];
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution S;
  string s = "abadfba#abfdaba";
  ic(S.findMaxCommon(s));
  // "aacecaaa"
  //  aacecaaa#aaacecaa
  //  aacecaa a#a aacecaa
  //  aaacecaa
  //   aaacecaa

  //  |       ||
  return 0;
}
