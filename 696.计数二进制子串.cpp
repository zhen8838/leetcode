/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int countBinarySubstrings(string s) {
    int a = 0, b = 0, pos = 0, cnt = 0, n = s.size();
    // 先pop一次多余的
    char last;
    last = s[pos];
    while (pos < n) {
      if (last == s[pos]) {
        pos++;
        a++;
      } else {
        break;
      }
    }
    // 循环找
    while (pos < n) {
      last = s[pos];
      while (pos < n) {
        if (last == s[pos]) {
          pos++;
          b++;
        } else {
          break;
        }
      }
      // ic(a, b);
      cnt += min(a, b);
      // 当前值赋值给下一个
      a = b;
      b = 0;
    }
    return cnt;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  string str = "10101";
  ic(s.countBinarySubstrings(str));
  return 0;
}
