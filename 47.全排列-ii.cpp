/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  vector<vector<int>> ans;

 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end(), less<int>());
    vector<int> track;
    dfs(nums, track);
    return ans;
  }
  void dfs(vector<int>& nums, vector<int>& track) {
    if (0 == nums.size()) {
      ans.push_back(track);
      return;
    }

    for (size_t i = 0; i < nums.size(); i++) {
      // remove duplicate
      if (i > 0 and nums[i - 1] == nums[i]) {
        continue;
      }

      track.push_back(nums[i]);
      nums.erase(nums.begin() + i);
      dfs(nums, track);
      nums.insert(nums.begin() + i, track.back());
      track.pop_back();
    }
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{1, 2,3};
  Solution s;
  ic(s.permuteUnique(nums));
  return 0;
}
