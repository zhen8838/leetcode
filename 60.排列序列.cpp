/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */
// @lc code=start
class Solution {
 public:
  string getPermutation(int n, int k) {
    vector<int> steps(n + 1, 1);
    string nums, track;
    for (int i = 1; i <= n; i++) {
      steps[i] = steps[i - 1] * i;
      nums.push_back(i + '0');
    }
    return dfs(nums, track, steps, k, nums.size());
  }

  string dfs(string& nums, string& track, vector<int>& steps, int k, int n) {
    if (nums.size() == 0) {
      return track;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (k > steps[n - 1]) {
        k -= steps[n - 1];
        continue;
      }
      track.push_back(nums[i]);
      nums.erase(nums.begin() + i);
      return dfs(nums, track, steps, k, n - 1);
    }
    return track;
  }
};
// @lc code=end
