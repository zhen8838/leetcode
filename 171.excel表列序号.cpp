/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel表列序号
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int titleToNumber(string s) {
    uint64_t res = 0, mul = 1, t;
    for (int i = s.size() - 1; i >= 0; i--) {
      t = s[i] - 'A' + 1;
      res += mul * t;
      mul *= 26;
    }
    return res;
  }
};
// @lc code=end
int main(int argc, char const* argv[]) {
  Solution s;
  ic(s.titleToNumber("CFDGSXM"));
  return 0;
}
