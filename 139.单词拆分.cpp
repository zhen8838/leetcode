/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */
#include <unordered_set>

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> uset(wordDict.begin(), wordDict.end());

    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i < s.size() + 1; i++) {
      for (int j = i - 1; j >= 0; j--) {
        // ic(i,j);
        dp[i] = dp[j] and uset.count(s.substr(j, i - j));
        if (dp[i]) {
          break;
        }
      }
    }

    return dp.back();
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  string s = "aaaaaaa";
  Vec<string> dict{"aaaa", "aaa"};
  Solution S;
  ic(S.wordBreak(s, dict));
  return 0;
}
