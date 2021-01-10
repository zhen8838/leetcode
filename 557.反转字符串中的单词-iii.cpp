/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  string reverseWords(string s) {
    string::size_type spos = 0, epos = s.find_first_of(' ', 0);
    while (epos != string::npos) {
      reverse(s.begin() + spos, s.begin() + epos);
      spos = epos + 1;
      epos = s.find_first_of(' ', epos + 1);
    }
    reverse(s.begin() + spos, s.end());
    return s;
  }
};
// @lc code=end
