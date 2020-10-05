/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */
#include "commom.hpp"

// @lc code=start
class Solution {
 public:
  string countAndSay(int n) {
    string base = "1";
    string out = "";
    vector<char> cbuf;
    vector<int> nbuf;
    for (size_t k = 0; k < n - 1; k++) {
      // 找一个方法统计一下然后循环构造函数即可。
      cbuf.push_back(base[0]);
      nbuf.push_back(1);
      int j = 0;
      for (size_t i = 1; i < base.size(); i++) {
        if (cbuf[j] == base[i]) {
          nbuf[j]++;
        } else {
          cbuf.push_back(base[i]);
          nbuf.push_back(1);
          j++;
        }
        // pvec(cbuf);
        // pvec(nbuf);
      }
      for (size_t i = 0; i < cbuf.size(); i++) {
        out += (nbuf[i] + '0');
        out += cbuf[i];
      }
      base = out;
      out.clear();
      cbuf.clear();
      nbuf.clear();
    }
    return base;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution S;
  auto out = S.countAndSay(3);
  pscalr(out);
  return 0;
}
