/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 */
#include <string>
#include <unordered_map>

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int calculate(string s) {
    vector<string> stk;
    vector<int> lasts;
    s.insert(s.begin(), '(');
    s.push_back(')');
    string c;
    unordered_map<string, function<long(const long&, const long&)> > umap{
        {"+", [](const long& a, const long& b) { return a + b; }},
        {"-", [](const long& a, const long& b) { return a - b; }}};
    for (int i = 0; i < s.size(); i++) {
      c = s[i];
      if (c == " ") {
        continue;
      } else if (c == "(") {
        lasts.push_back(stk.size());
        stk.push_back(c);
      } else if (c == ")") {
        if (stk.size() > lasts.back() + 3) {
          stk.back() = to_string(calc(umap, stk));
        } else {
          string t = stk.back();
          stk.pop_back();
          stk.back() = t;
        }
        lasts.pop_back();
      } else if (c == "+") {
        if (stk.size() > lasts.back() + 3) {
          stk.push_back(to_string(calc(umap, stk)));
        }
        stk.push_back(c);
      } else if (c == "-") {
        if (stk.size() > lasts.back() + 3) {
          stk.push_back(to_string(calc(umap, stk)));
        } else if (stk.size() == lasts.back() + 1) {
          stk.push_back("0");
        }
        stk.push_back(c);
      } else {
        if (stk.size() and isdigit(stk.back().back())) {
          stk.back().append(c);
        } else {
          stk.push_back(c);
        }
      }
    }
    return stol(stk.back());
  }

  long calc(
      unordered_map<string, function<long(const long&, const long&)> >& umap,
      vector<string>& stk) {
    string a, b, op;
    b = stk.back(), stk.pop_back();
    op = stk.back(), stk.pop_back();
    a = stk.back(), stk.pop_back();
    return umap[op](stol(a), stol(b));
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  string s = "1-(5)";
  Solution S;
  ic(S.calculate(s));
  return 0;
}
