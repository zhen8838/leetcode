/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */
#include <unordered_set>

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  string removeDuplicateLetters(string s) {
    // 需要用set去确保当前元素只出现过一次
    vector<int> cnt(26, -1), uset(26, 0);
    for (size_t i = 0; i < s.size(); i++) {
      cnt[c2i(s[i])]++;
    }
    string r = "";
    for (auto&& c : s) {
      if (not uset[c2i(c)]) {
        // 当前面有值时,且前面值可删,且当前值比前面的值小,就一直删下去
        while (r.size() and cnt[c2i(r.back())] and r.back() > c) {
          cnt[c2i(r.back())]--;
          uset[c2i(r.back())] = 0;  // 被pop的时候需要从set中去除
          r.pop_back();
        }
        r.push_back(c);
        uset[c2i(c)] = 1;
      } else {
        cnt[c2i(c)]--;  // 如果已经出现过了一次,那么直接丢弃
      }
    }

    return r;
  }

  inline int c2i(char c) { return c - 'a'; }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  string s = "cdadabcc";
  Solution S;
  ic(S.removeDuplicateLetters(s));
  return 0;
}
