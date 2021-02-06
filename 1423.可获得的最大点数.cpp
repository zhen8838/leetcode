/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] 可获得的最大点数
 */

// @lc code=start
class Solution {
 public:
  int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size(), ans = 0, sum = 0;
    for (int i = n - k; i < n; i++) {
      sum += cardPoints[i];
    }
    ans = sum;
    int s = n - k;
    for (int i = 0; i < k; i++) {
      sum -= cardPoints[(s + i) % n];
      sum += cardPoints[(n + i) % n];
      ans = max(ans, sum);
    }
    return ans;
  }
};
// @lc code=end
