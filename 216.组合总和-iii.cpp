/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  vector<vector<int>> ans;

 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> track;
    dfs(track, 1, k, 0, n);
    return ans;
  }
  void dfs(vector<int> track, int pos, int k, int sum, int n) {
    if (k == 0) {
      if (sum == n) {
        ans.push_back(track);
      }
      return;
    }
    for (size_t i = pos; i < 10; i++) {
      // 剪枝
      if (sum + (k * i) + (k - 1) > n) {
        break;
      }

      track.push_back(i);
      dfs(track, i + 1, k - 1, sum + i, n);
      track.pop_back();
    }
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  ic(s.combinationSum3(3, 7));
  return 0;
}
