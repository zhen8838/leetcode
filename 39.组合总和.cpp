/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  vector<vector<int>> ans;

 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end(), less<int>());
    vector<int> track;
    dfs(candidates, track, 0, target);
    return ans;
  }

  void dfs(vector<int>& candidates, vector<int> track, int pos, int target) {
    if (target == 0) {
      ans.push_back(track);
      return;
    }
    for (size_t i = pos; i < candidates.size(); i++) {
      if (target >= candidates[i]) {
        track.push_back(candidates[i]);
        // 设置起点进行去重,下一次只会从当前节点开始搜索
        dfs(candidates, track, i, target - candidates[i]);
        track.pop_back();
      } else {
        break;
      }
    }
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> candidates{2, 3, 6, 7};
  int target = 7;
  Solution s;
  ic(s.combinationSum(candidates, target));
  return 0;
}
