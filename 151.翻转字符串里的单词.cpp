/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  string reverseWords(string s) {
    s.insert(s.begin(),' ');
    string::iterator left = s.begin(), right = left;
    char c;
    while (left != s.end()) {
      while (left != s.end() and *left == ' ') {
        s.erase(left);
      }
      if (left == s.end()) {
        break;
      }
      s.insert(left, ' ');
      right = left + 1;
      while (right != s.end() and *right != ' ') {
        right++;
      }
      reverse(left, right);
      left = right;
    }
    reverse(s.begin(), s.end());
    s.erase(s.begin());
    return s;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  string s = "the sky is blue";
  Solution S;
  ic(S.reverseWords(s));
  // auto p = s.begin();
  return 0;
}
