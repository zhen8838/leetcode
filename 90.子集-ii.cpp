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
    dfs(nums, track, 0);
    return ans;
  }
  void dfs(vector<int>& nums, vector<int>& track, int p) {
    ans.push_back(track);
    if (p == nums.size()) { return; }
    for (int i = p; i < nums.size(); i++) {
      if (i > p and nums[i - 1] == nums[i]) { continue; }
      track.push_back(nums[i]);
      dfs(nums, track, i + 1); 
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
