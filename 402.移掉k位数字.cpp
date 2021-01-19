/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  string removeKdigits(string num, int k) {
    string s;
    /* 每次我们只看前面那个数字,如果前面那个数字比我们大,那么就可以移除它 */
    for (size_t i = 0; i < num.size(); i++) {
      while (k and s.size() and s.back() > num[i]) {
        s.pop_back();
        k--;
      }
      s.push_back(num[i]);
    }
    while (k) {
      s.pop_back();
      k--;
    }
    if (s.empty()) {
      return "0";
    }
    auto pos = s.find_first_not_of('0');
    if (pos == string::npos) {
      return "0";
    }
    return s.substr(pos);
  }
};
// @lc code=end
