/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  string minWindow(string s, string t) {
    int umap[256] = {0};
    for (auto&& c : t) umap[c]++;
    int cnt = 0, minlen = s.size();
    string res = "";
    for (int r = 0, l = 0; r < s.size(); r++) {
      umap[s[r]]--;
      if (umap[s[r]] >= 0) cnt++;
      while (cnt == t.size()) {
        int len = r - l + 1;
        if (len <= minlen) {
          minlen = len;
          res = s.substr(l, len);
        }
        umap[s[l]]++;
        if (umap[s[l]] > 0) cnt--;
        l++;
      }
    }
    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  string a = "ADOBECODEBANC", b = "ABC";
  ic(s.minWindow(a, b));
  return 0;
}
