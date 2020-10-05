/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int myAtoi(string s) {
    char prefix = '+';
    int num = 0;
    size_t i = 0, j = 1;
    int upbound = (INT32_MAX / 10), upodd = INT32_MAX % 10;
    int lowbound = (INT32_MIN / 10), lowodd = INT32_MIN % 10;

    for (; i < s.size(); i++) {
      if (s[i] == ' ') {
        continue;
      } else {
        break;
      }
    }

    if (s[i] == '+' or s[i] == '-') {
      prefix = s[i++];
      if (!isdigit(s[i])) {
        return 0;
      }
    } else if (!isdigit(s[i])) {
      return 0;
    }

    for (; isdigit(s[i]); i++) {
      int tmp = (s[i] - '0');
      if (prefix == '-') {
        tmp = -tmp;
      }

      if ((num > upbound) || (num == upbound && tmp > upodd)) {
        return INT32_MAX;
      }
      if ((num < lowbound) || (num == lowbound && tmp < lowodd)) {
        return INT32_MIN;
      }

      // pscalr(num);
      // pscalr(tmp);
      num = num * 10 + tmp;
    }
    // pscalr(-2147483649 < INT32_MIN);
    return num;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  auto S = Solution();
  string input("-2147483649");
  auto num = S.myAtoi(input);
  pscalr(num);
  return 0;
}
