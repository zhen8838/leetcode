/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */
#include <unordered_map>

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    int count = 0;
    int sum = 0;
    unordered_map<int, int> umap;
    umap[sum] = 1;
    for (size_t i = 0; i < nums.size(); i++) {
      sum += nums[i];
      // 我们累积所有的序列和,如果当前序列和减去一个值,并存在,那么表示从那个值开始到当前的序列和即为k;
      if (umap.count(sum - k)) {
        count += umap[sum - k];
      }
      umap[sum]++;
    }

    return count;
  }
};
// @lc code=end
