/*
 * @lc app=leetcode.cn id=214 lang=cpp
 *
 * [214] 最短回文串
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  string shortestPalindrome(string s) {
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
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution S;
  string s = "aacecaaaaa";
  // "aacecaaa"
  //  0123456789
  //  |       ||
  return 0;
}
