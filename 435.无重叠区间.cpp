/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(),
         [](vector<int>& a, vector<int>& b) {
           return a[0] < b[0] or (a[0] == b[0] and a[1] < b[1]);
         });
    int l, r, cnt = 0;
    for (size_t i = 0; i < intervals.size(); i++) {
      int nl = intervals[i][0], nr = intervals[i][1];
      if (i > 0) {
        if (l <= nl and nr <= r) {
          // 当前范围在历史范围里面，那么删除历史范围
          cnt++;
        } else if (l <= nl and r <= nr and nl < r) {
          // 当前范围比历史范围大。
          cnt++;
          continue;
        }
      }
      l = nl;
      r = nr;
    }
    return cnt;
  }
};
// @lc code=end
