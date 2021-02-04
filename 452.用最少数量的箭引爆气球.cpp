/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
 public:
  int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
      return a[0] < b[0] or (a[0] == b[0] and a[1] < b[1]);
    });
    int cnt = 0, l, r;
    for (auto&& p : points) {
      if (cnt == 0) {
        l = p[0];
        r = p[1];
        cnt++;
      } else {
        if (max(l, p[0]) <= r) {
          l = max(l, p[0]);
          r = min(r, p[1]);
        } else {
          l = p[0];
          r = p[1];
          cnt++;
        }
      }
    }
    return cnt;
  }
};
// @lc code=end
