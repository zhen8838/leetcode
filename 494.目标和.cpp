/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
 private:
  int res = 0;

 public:
  int findTargetSumWays(vector<int>& nums, int S) {
    sort(nums.begin(), nums.end(), greater<int>());
    dfs(nums, 0, (long)S, nums.size(), 0);
    return res;
  }
  void dfs(vector<int>& nums, int pos, long target, int n, long ans) {
    if (pos == n) {
      if (ans == target) {
        res++;
      }
      return;
    }
    for (auto&& k : {-1, 1}) {
      if (abs(target - (ans + k * nums[pos])) > (n - (pos + 1)) * nums[pos]) {
        continue;
      }
      dfs(nums, pos + 1, target, n, ans + k * nums[pos]);
    }
  }
};
// @lc code=end
