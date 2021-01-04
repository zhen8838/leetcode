/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  string addStrings(string num1, string num2) {
    auto p1 = num1.rbegin(), p2 = num2.rbegin();
    int mod = 0, sum;
    string res;
    while (p1 != num1.rend() and p2 != num2.rend()) {
      sum = ((*p1) - '0') + ((*p2) - '0') + mod;
      if (sum >= 10) {
        mod = 1;
        sum -= 10;
      } else {
        mod = 0;
      }
      res.push_back(sum + '0');
      p1++;
      p2++;
    }
    if (p1 == num1.rend()) {
      while (p2 != num2.rend()) {
        sum = ((*p2) - '0') + mod;
        if (sum >= 10) {
          mod = 1;
          sum -= 10;
        } else {
          mod = 0;
        }
        res.push_back(sum + '0');
        p2++;
      }
    } else {
      while (p1 != num1.rend()) {
        sum = ((*p1) - '0') + mod;
        if (sum >= 10) {
          mod = 1;
          sum -= 10;
        } else {
          mod = 0;
        }
        res.push_back(sum + '0');
        p1++;
      }
    }
    if (mod > 0) {
      res.push_back(mod + '0');
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  string num1 = "189", num2 = "36";
  Solution s;
  ic(s.addStrings(num1, num2));
  return 0;
}
