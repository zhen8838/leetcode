/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  string convert(string s, int numRows) {
    vector<vector<char>> z(numRows, vector<char>{});
    if (numRows == 1) {
      return s;
    }

    int cnt = 0;
    while (cnt < s.size()) {
      for (size_t i = 0; i < numRows; i++) {
        if (cnt < s.size()) {
          z[i].push_back(s[cnt++]);
        }
      }
      for (size_t i = numRows - 2; i > 0; i--) {
        if (cnt < s.size()) {
          z[i].push_back(s[cnt++]);
        }
      }
    }
    // ic(z);
    string res;
    for (auto&& v : z) {
      for (auto&& c : v) {
        res.push_back(c);
      }
    }
    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  string s = "PAYPALISHIRING";
  Solution S;
  ic(S.convert(s, 2));
  return 0;
}
