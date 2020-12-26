/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int maxEnvelopes(vector<vector<int>>& envelopes) {
    // maybe we need sort!
    sort(envelopes.begin(), envelopes.end(),
         [](vector<int>& a, vector<int>& b) {
           if (a[0] < b[0]) {
             return true;
           } else if (a[0] == b[0]) {
             return a[1] < b[1];
           } else {
             return false;
           }
         });
    // ic(envelopes);
    vector<int> dp(envelopes.size(), 1);
    int ans=0;
    for (size_t i = 0; i < envelopes.size(); i++) {
      for (size_t j = 0; j < i; j++) {
        if (envelopes[i][0] > envelopes[j][0] and
            envelopes[i][1] > envelopes[j][1]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      ans = max(ans, dp[i]);
    }
    return ans;
  }
};
// @lc code=end
int main(int argc, char const* argv[]) {
  // vector<vector<int>> env = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
  vector<vector<int>> env = {{5, 4}};
  Solution s;
  ic(s.maxEnvelopes(env));
  return 0;
}
