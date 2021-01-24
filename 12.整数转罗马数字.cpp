/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  string intToRoman(int num) {
    string res;
    map<int, string> umap{
        {1, "I"},   {4, "IV"},   {5, "V"},    {9, "IX"},  {10, "X"},
        {40, "XL"}, {50, "L"},   {90, "XC"},  {100, "C"}, {400, "CD"},
        {500, "D"}, {900, "CM"}, {1000, "M"},
    };
    int m = 10;
    while (num) {
      auto p = umap.rbegin();
      while (p != umap.rend() and p->first > num) {
        p++;
      }
      num -= p->first;
      res.append(p->second);
    }
    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  ic(s.intToRoman(1994));
  return 0;
}
