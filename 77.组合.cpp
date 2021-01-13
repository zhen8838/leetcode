/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  vector<vector<int>> ans;

 public:
  vector<vector<int>> combine(int n, int k) {
    vector<int> track;
    dfs(track, 1, n, k);
    return ans;
  }
  void dfs(vector<int>& track, int pos, int n, int k) {
    if (k == 0) {
      ans.push_back(track);
      return;
    }
    for (size_t i = pos; i <= n; i++) {
      track.push_back(i);
      dfs(track, i + 1, n, k - 1);
      track.pop_back();
    }
  }
};
// @lc code=end
