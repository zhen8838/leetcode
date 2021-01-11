/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  string multiply(string num1, string num2) {
    string s(num1.size() + num2.size(), '0');
    // reverse(num1.begin(), num1.end());
    // reverse(num2.begin(), num2.end());
    int mod;
    for (size_t i = num1.size() - 1; i >= 0; i--) {
      int n1 = num1[i] - '0';
      for (size_t j = num2.size() - 1; j >= 0; j--) {
        int sum = n1 * (num2[j] - '0');
        int add = s[i + j] - '0' + mod + mul % 10;
        s[i + j] = add % 10;
        mod = add / 10;
        for (size_t z = i + j; z < s.size(); z++) {
          // s[i+j+1]
        }
      }
    }
  }
};
// @lc code=end
