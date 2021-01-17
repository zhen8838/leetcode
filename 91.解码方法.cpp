/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */
#include <unordered_set>

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int numDecodings(string s) {
    // 不用set优化一波
    // unordered_set<string> uset;
    // for (size_t i = 1; i < 27; i++) {
    //   uset.emplace(to_string(i));
    // }
    int a = 0, b = 0, c = 0;
    a = isvalid(s, 0, 1);
    if (s.size() < 2) {
      return a;
    }
    // 如果当前能被转换,那么和前面的算为一个,否则前面的算0,
    b = (isvalid(s, 1, 1) ? a : 0) + isvalid(s, 0, 2);
    c = b;
    for (size_t i = 2; i < s.size(); i++) {
      c = isvalid(s, i, 1) ? b : 0;
      c += isvalid(s, i - 1, 2) ? a : 0;
      // ic(i, a, b, c);
      a = b;
      b = c;
    }
    return c;
  }
  // int numDecodings(string s) {
  //   // 不用set优化一波
  //   unordered_set<string> uset;
  //   for (size_t i = 1; i < 27; i++) {
  //     uset.emplace(to_string(i));
  //   }
  //   int a = 0, b = 0, c = 0;
  //   a = uset.count(s.substr(0, 1));
  //   if (s.size() < 2) {
  //     return a;
  //   }
  //   // 如果当前能被转换,那么和前面的算为一个,否则前面的算0,
  //   b = (uset.count(s.substr(1, 1)) ? a : 0) + uset.count(s.substr(0, 2));
  //   c = b;
  //   for (size_t i = 2; i < s.size(); i++) {
  //     c = uset.count(s.substr(i, 1)) ? b : 0;
  //     c += uset.count(s.substr(i - 1, 2)) ? a : 0;
  //     ic(i, a, b, c, s.substr(i, 1), s.substr(i - 1, 2));
  //     a = b;
  //     b = c;
  //   }
  //   return c;
  // }

  bool isvalid(string& s, int i, int n) {
    if (n == 1) {
      // ic(s[i]);
      return s[i] != '0';
    }
    // ic(s[i], s[i + 1]);
    return (s[i] == '1') or (s[i] == '2' and s[i + 1] < '7');
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  string s = "2611055971756562";
  Solution S;
  ic(S.numDecodings(s));
  // ic(s.substr(2, 1));
  // ic(s.substr(1, 2));
  return 0;
}
