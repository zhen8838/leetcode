/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
 public:
  int candy(vector<int>& ratings) {
    int n = ratings.size(), l = 0, r = n - 1;
    int cnt = n;
    vector<int> dp(n, 1);
    for (int i = 0; i < n - 1; i++) {
      if (ratings[l] < ratings[l + 1]) {
        dp[l + 1] = max(dp[l + 1], dp[l] + 1);
      }
      if (ratings[r] < ratings[r - 1]) {
        dp[r - 1] = max(dp[r - 1], dp[r] + 1);
      }
      l++;
      r--;
    }
    return accumulate(dp.begin(), dp.end(), 0);
  }
};
// @lc code=end
