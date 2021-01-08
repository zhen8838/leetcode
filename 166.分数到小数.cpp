/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 */
#include <unordered_map>

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    int64_t num = abs((int64_t)numerator), den = abs((int64_t)denominator);
    string res;
    // 特判0
    if (numerator == 0) {
      res.push_back('0');
      return res;
    }

    // 先加符号
    if ((numerator < 0) != (denominator < 0)) {
      res.push_back('-');
    }

    // 加第一位
    res.append(to_string(num / den));
    // 如果刚好是倍数那么结束
    if (num % den == 0) {
      return res;
    }
    // 除完之后没有还有余数,那么就是进入小数模式
    res.push_back('.');

    unordered_map<uint64_t, size_t> dict;
    // 如果一直不能整除就继续循环
    while (num % den) {
      // 每次让除数增大
      num = (num % den) * 10;
      if (dict.find(num) != dict.end()) {
        // 每次都在寻找这个商是否出现过,如果出现过,那么就在记录的位置插入括号
        res.insert(dict[num], "(");
        res.push_back(')');
        break;
      }
      dict[num] = res.size();
      res.append(to_string(num / den));
    }
    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  ic(s.fractionToDecimal(-50, 3));
  return 0;
}
