/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
  vector<vector<string>> res;

 public:
  vector<vector<string>> solveNQueens(int n) {
    unordered_set<int> cloums;
    unordered_set<int> right;
    unordered_set<int> left;
    vector<string> track(n, string(n, '.'));
    dfs(track, cloums, right, left, 0, n);
    return res;
  }
  void dfs(vector<string>& track, unordered_set<int>& cloums,
           unordered_set<int>& right, unordered_set<int>& left, int y, int n) {
    if (y == n) {
      res.push_back(track);
      return;
    }
    for (int x = 0; x < n; x++) {
      if (cloums.count(x)) {
        continue;
      }
      int r = x - y;
      if (right.count(r)) {
        continue;
      }
      int l = x + y;
      if (left.count(l)) {
        continue;
      }
      track[y][x] = 'Q';
      cloums.insert(x);
      right.insert(r);
      left.insert(l);
      dfs(track, cloums, right, left, y + 1, n);
      track[y][x] = '.';
      cloums.erase(x);
      right.erase(r);
      left.erase(l);
    }
  }
};
// @lc code=end
