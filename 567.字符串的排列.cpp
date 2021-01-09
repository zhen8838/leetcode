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
    // 只要两个字符串的频率相同,那么他们肯定存在全排列是相同的.
    int s = 0, e = 0;
    vector<int> dict1(26, 0), dict2(26, 0);
    for (auto&& c : s1) {
      dict1[c - 'a']++;
    }

    while (e < s2.size()) {
      if (e < s1.size()) {
        dict2[s2[e] - 'a']++;
      } else {
        if (match(dict1, dict2)) {
          return true;
        } else {
          dict2[s2[s++] - 'a']--;
          dict2[s2[e] - 'a']++;
        }
      }
      e++;
    }
    if (e < s1.size()) {
      return false;
    }

    return match(dict1, dict2);
  }
  bool match(vector<int>& a, vector<int>& b) {
    for (size_t i = 0; i < a.size(); i++) {
      if (a[i] != b[i]) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) { return 0; }
