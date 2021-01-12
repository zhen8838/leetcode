/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  string decodeString(string s) {
    int pos = 0;
    string res;
    while (pos < s.size()) {
      while (pos < s.size() and not isdigit(s[pos])) {
        res.push_back(s[pos]);
        pos++;
      }
      if (pos < s.size()) {
        // repeat will >10
        string repeat;
        while (s[pos] != '[') {
          repeat.push_back(s[pos++]);
        };
        // ic(repeat);
        int repeatn = stoi(repeat);
        int left = 1;
        int start = ++pos;
        int n = 0;
        while (left != 0) {
          ++pos;
          ++n;
          if (s[pos] == '[') {
            left++;
          } else if (s[pos] == ']') {
            left--;
          }
        }
        // ic(s.substr(start, n), start, n - 1, s[pos]);
        string subs = decodeString(s.substr(start, n));
        while (repeatn-- > 0) {
          res.append(subs);
        }
      }
      pos++;
    }
    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  // string S(4, "a2[c]");
  // ic(S);
  ic(s.decodeString("13[a2[c]]"));
  return 0;
}
