/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int evalRPN(vector<string>& tokens) {
    stack<int> s;
    int l, r, res;
    for (auto&& token : tokens) {
      if (token == "+" or token == "-" or token == "*" or token == "/") {
        l = s.top();
        s.pop();
        r = s.top();
        s.pop();
        if (token == "+") {
          res = r + l;
        } else if (token == "-") {
          res = r - l;
        } else if (token == "*") {
          res = r * l;
        } else if (token == "/") {
          res = r / l;
        }
        s.push(res);
      } else {
        s.push(stoi(token));
      }
    }
    return s.top();
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<string> tokens = {"4", "13", "5", "/", "+"};
  ic(s.evalRPN(tokens));
  return 0;
}
