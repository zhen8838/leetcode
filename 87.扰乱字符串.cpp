/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool isScramble(string s1, string s2) {
    // 因为他是递归的方式进行转换的，那么如果s1是被s2转换的，那么他肯定也是一步一步的被转换过去的，这时候我们就从大字符串到小字符串递归
    if (s1 == s2) { return true; }
    if (not check(s1, s2)) { return false; }
    for (int i = 1; i < s1.size(); i++) {
      // 把s1和s2分成0～i，i～n两块
      string s1a = s1.substr(0, i), s1b = s1.substr(0 + i, s1.size() - i);
      string s2a = s2.substr(0, i), s2b = s2.substr(0 + i, s2.size() - i);

      if (isScramble(s1a, s2a) and isScramble(s1b, s2b)) return true;
      if (isScramble(s1a, s2b) and isScramble(s1b, s2a)) return true;
    }
    return false;
  }

  bool check(string s1, string s2) {
    // 如果词频不一样那么肯定是不匹配的。
    if (s1.size() != s2.size()) { return false; }

    int cnt[26] = {0};
    for (int i = 0; i < s1.size(); i++) {
      cnt[s1[i] - 'a']++;
      cnt[s2[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
      if (cnt[i] != 0) return false;
    }
    return true;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  string s1 = "great", s2 = "regeat";
  ic(s.isScramble(s1, s2));
  return 0;
}
