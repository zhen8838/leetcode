/*
 * @lc app=leetcode.cn id=477 lang=cpp
 *
 * [477] 汉明距离总和
 */
#include "commom.hpp"

// @lc code=start
class Solution {
 public:
  int totalHammingDistance(vector<int>& nums) {
    vector<int> cnt(32, 0);
    uint mask = 1;
    for (size_t i = 0; i < 32; i++) {
      for (auto&& num : nums) {
        if ((num & mask) == 0) {
          cnt[i]++;
        }
      }
      mask <<= 1;
    }
    int ans = 0;
    for (auto&& k : cnt) {
      ans += k * (nums.size() - k);
    }

    return ans;
  }
};
// @lc code=end
