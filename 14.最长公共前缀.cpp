/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string com;
    set<char> tmp;
    size_t i = 0;
    if (strs.size() < 1) {
      return com;
    }
    for (size_t k = 0; k < strs.size(); k++) {
      if (strs[k].size() < 1) {
        return com;
      }
    }

    while (true) {
      // pscalr(i);
      for (size_t j = 0; j < strs.size(); j++) {
        tmp.insert(strs[j][i]);
        if (tmp.size() != 1 or i == strs[j].size()) {
          return com;
        }
      }
      i++;
      com += *tmp.begin();
      tmp.clear();
    }
    return com;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution S;
  vector<string> strs = {"a"};
  auto out = S.longestCommonPrefix(strs);
  pscalr(out);
  return 0;
}
