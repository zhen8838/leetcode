/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution {
  vector<string> res;

 public:
  vector<string> letterCasePermutation(string S) {
    dfs(S, 0);
    return res;
  }

  void dfs(string& s, int pos) {
    for (int i = pos; i < s.size(); i++) {
      if (isdigit(s[i])) { continue; }
      s[i] = toupper(s[i]);
      dfs(s, i + 1);
      s[i] = tolower(s[i]);
      dfs(s, i + 1);
      return;
    }
    res.push_back(s);
    return;
  }
};
// @lc code=end
