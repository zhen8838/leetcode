/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
 public:
  string removeDuplicates(string S) {
    string s;
    for (int i = 0; i < S.size(); i++) {
      if (s.size() and S[i] == s.back()) {
        s.pop_back();
        continue;
      }
      s.push_back(S[i]);
    }
    return s;
  }
};
// @lc code=end
