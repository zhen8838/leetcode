/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  vector<vector<int>> ans;

 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
        if (i > pos and candidates[i - 1] == candidates[i]) {
          // 如果当前元素和上面那个元素相同,那么跳过,因为此元素的结果已经有了
          continue;
        }
        track.push_back(candidates[i]);
        // 设置起点进行去重,下一次只会从当前节点后面开始搜索
        dfs(candidates, track, i + 1, target - candidates[i]);
        track.pop_back();
      } else {
        break;
      }
    }
  }
};
// @lc code=end
