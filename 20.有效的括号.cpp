/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool isValid(string s) {
    auto cnt = stack<char>();
    for (auto&& c : s) {
      if (cnt.size()) {
        if (isClose(cnt.top(), c)) {
          cnt.pop();
        } else {
          cnt.push(c);
        }
      } else {
        cnt.push(c);
      }
    }
    if (cnt.size()) {
      return false;
    } else {
      return true;
    }
  }

  bool isClose(char& left, char& right) {
    if ((left == '(' and right == ')') or (left == '[' and right == ']') or
        (left == '{' and right == '}')) {
      return true;
    } else {
      return false;
    }
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  auto s = Solution();
  pscalr(s.isValid("([)]"));
  return 0;
}
