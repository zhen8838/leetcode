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
    if (num1 == "0" or num2 == "0") {
      return "0";
    }

    // string s(num1.size() + num2.size(), '0');
    vector<int> s(num1.size() + num2.size(), 0);
    // reverse(num1.begin(), num1.end());
    // reverse(num2.begin(), num2.end());
    for (int i = num1.size() - 1; i >= 0; i--) {
      int n1 = num1[i] - '0';
      for (int j = num2.size() - 1; j >= 0; j--) {
        int n2 = num2[j] - '0';
        int sum = (s[i + j + 1]) + n1 * n2;
        s[i + j + 1] = sum % 10;
        // NOTE when the s[i + j]>10, in next iter will process;
        s[i + j] += sum / 10;
        // ic(i + j, s);
      }
    }
    while (s[0] == 0) {
      s.erase(s.begin());
    }
    string res;
    for (auto&& c : s) {
      res.push_back(c + '0');
    }
    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  string num1 = "789", num2 = "789";
  Solution s;
  ic(s.multiply(num1, num2));
  return 0;
}
