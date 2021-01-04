/*
 * @lc app=leetcode.cn id=1207 lang=cpp
 *
 * [1207] 独一无二的出现次数
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool uniqueOccurrences(vector<int>& arr) {
    map<int, int> dict;
    set<int> freq;
    for (auto&& a : arr) {
      dict[a]++;
    }
    for (auto&& item : dict) {
      freq.emplace(item.second);
    }
    return dict.size() == freq.size();
  }
};
// @lc code=end
