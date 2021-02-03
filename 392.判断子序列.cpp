/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
 public:
  bool isSubsequence(string s, string t) {
    int j = 0;
    for (size_t i = 0; i < t.size(); i++) {
      if (t[i] == s[j]) {
        j++;
        if (j == s.size()) {
          break;
        }
      }
    }
    if (j != s.size()) {
      return false;
    }
    return true;
  }
};
// @lc code=end
