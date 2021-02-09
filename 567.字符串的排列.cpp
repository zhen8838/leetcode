/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool checkInclusion(string s1, string s2) {
    vector<int> amap(26, 0), bmap(26, 0);
    for (auto&& c : s1) amap[c - 'a']++;
    int cnt = 0;
    for (int r = 0, l = 0; r < s2.size(); r++) {
      bmap[s2[r] - 'a']++;
      cnt++;
      if (cnt == s1.size()) {
        if (check(amap, bmap)) {
          return true;
        }
        bmap[s2[l] - 'a']--;
        l++;
        cnt--;
      }
    }
    return false;
  }

  bool check(vector<int>& amap, vector<int>& bmap) {
    for (int i = 0; i < 26; i++) {
      if (amap[i] != bmap[i]) return false;
    }
    return true;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  //   "ab"
  // "eidboaoo"
  Solution s;
  string s1 = "ab", s2 = "eidboaoo";
  ic(s.checkInclusion(s1, s2));
  return 0;
}
