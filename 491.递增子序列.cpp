/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 递增子序列
 */
#include "commom.hpp"
#include <unordered_set>
// @lc code=start
class Solution {
  vector<vector<int>> res;

 public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<int> track;
    dfs(nums, track, 0, nums.size());
    return res;
  }

  void dfs(vector<int>& nums, vector<int>& track, int first, int n) {
    if (track.size() > 1) {
      res.push_back(track);
    }
    if (first == n) {
      return;
    }
    unordered_set<int> uset;  // 使用set对本层元素进行去重
    for (size_t i = first; i < n; i++) {
      if ((track.empty() || track.back() <= nums[i]) &&
          // 再判断是否重复
          (uset.find(nums[i]) == uset.end())) {
        track.push_back(nums[i]);
        uset.insert(nums[i]);
        dfs(nums, track, i + 1, n);
        track.pop_back();
      }
    }
  }

  vector<vector<int>> countSubsequences(vector<int>& nums) {
    // 利用dp对子序列情况进行计数
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
    size_t end;
    for (size_t step = 1; step < nums.size(); step++) {
      for (size_t start = 0; start < nums.size() - step; start++) {
        end = start + step;
        // 首先跳跃着去寻找可能的序列,如果找到那么+1,并且对重复序列剪枝
        for (size_t next_end = end + 1; next_end < nums.size(); next_end++) {
          if (nums[next_end] > nums[start] &&
              nums[next_end - 1] != nums[next_end]) {
            dp[start][next_end]++;
          }
        }
        // 当前序列的总个数由左边和下面的节点组成.,同时判断当前位置是否需要加上
        // 主要是为了避免只有7,7这样的序列.
        dp[start][end] += (dp[start][end - 1] + dp[start + 1][end] +
                           (nums[start] <= nums[end] ? 1 : 0));
        // ic(dp);
      }
    }
    return dp;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{4, 6, 7, 7};
  Solution s;
  auto res = s.findSubsequences(nums);
  ic(res);
  return 0;
}
