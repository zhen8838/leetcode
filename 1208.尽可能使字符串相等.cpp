/*
 * @lc app=leetcode.cn id=1208 lang=cpp
 *
 * [1208] 尽可能使字符串相等
 */

// @lc code=start
class Solution {
 public:
  int equalSubstring(string s, string t, int maxCost) {
    int n = s.size(), sumcost = 0, ans = 0;
    for (int r = 0, l = 0; r < n; r++) {
      sumcost += abs(s[r] - t[r]);
      if (sumcost > maxCost) {
        sumcost -= abs(s[l] - t[l]);
        l++;
      }
      ans = max(ans, r - l + 1);
    }
    return ans;
  }
};
// @lc code=end
