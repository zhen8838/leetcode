/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  vector<vector<int>> ans;

 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> track;
    dfs(nums, track, 0, nums.size());
    return ans;
  }
  void dfs(vector<int>& nums, vector<int>& track, int pos, int n) {
    ans.push_back(track);
    if (pos == n) {
      return;
    }
    for (size_t i = pos; i < n; i++) {
      if (i > pos and nums[i - 1] == nums[i]) {
        continue;
      }
      track.push_back(nums[i]);
      dfs(nums, track, i + 1, n);
      track.pop_back();
    }
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums{1, 2, 2};
  ic(s.subsetsWithDup(nums));
  return 0;
}
