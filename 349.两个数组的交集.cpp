/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */
#include <unordered_map>

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> dict;
    for (auto&& i : nums1) {
      dict[i] = 1;
    }
    vector<int> res;
    for (auto&& i : nums2) {
      if (dict[i] == 1) {
        res.push_back(i);
        dict[i]=0;
      }
    }
    return res;
  }
};
// @lc code=end
