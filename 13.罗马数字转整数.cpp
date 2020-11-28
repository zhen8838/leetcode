/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int romanToInt(string s) {
    map<char, int> d = {
        {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000},
    };
    char last = s[s.length() - 1];
    int res = d[last];
    for (int i = s.length() - 2; i >= 0; i--) {
      char cur = s[i];
      if (d[cur] < d[last])
        res -= d[cur];
      else
        res += d[cur];
      last = cur;
    }

    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  auto s = Solution();
  pscalr(s.romanToInt("MCMXCIV"));
  return 0;
}
