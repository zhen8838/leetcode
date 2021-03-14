/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */
#include <unordered_map>

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int calculate(string s) {
    deque<long> nums;
    deque<char> ops;
    unordered_map<char, int> umap{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
    int i = 0;
    long num = 0;
    while (i < s.size()) {
      if (s[i] == ' ') {
        i++;
      } else if (isdigit(s[i])) {
        num = 0;
        while (i < s.size() and isdigit(s[i])) {
          num = num * 10 + (s[i] - '0');
          i++;
        }
        nums.push_back(num);
      } else {
        // 每次加新的op的时候，将优先级大于等于当前op的老op进行计算。
        while (ops.size() and umap[ops.back()] >= umap[s[i]]) {
          calc(nums, ops);
        }
        ops.push_back(s[i]);
        i++;
      }
    }
    while (ops.size()) { calc(nums, ops); }
    return nums.front();
  }

  void calc(deque<long>& nums, deque<char>& ops) {
    long a, b, ans;
    b = nums.back(), nums.pop_back();
    a = nums.back(), nums.pop_back();
    char op = ops.back();
    ops.pop_back();
    switch (op) {
      case '+':
        ans = (a + b);
        break;
      case '-':
        ans = (a - b);
        break;
      case '*':
        ans = (a * b);
        break;
      case '/':
        ans = (a / b);
        break;
      default:
        break;
    }
    nums.push_back(ans);
  }
};
// @lc code=end
