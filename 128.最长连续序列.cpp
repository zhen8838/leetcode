/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> uset(nums.begin(), nums.end());
    int ans = 0;
    for (auto&& num : uset) {
      if (not uset.count(num - 1)) {
        // 如果没有比nums[i]更小的元素，那么nums[i]可能就是起点，我们开始遍历
        int cur = 1;
        int t = num;
        while (uset.count(t + 1)) {
          t++;
          cur++;
        }
        ans = max(ans, cur);
      }
    }
    return ans;
  }
};
// @lc code=end
