/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    multimap<int, int> d;
    vector<vector<int>> res;
    for (auto&& rg : intervals) {
      d.emplace(rg[0], rg[1]);
    }
    // ic(d);
    for (auto&& item : d) {
      if (res.empty()) {
        res.push_back(vector<int>{item.first, item.second});
      } else {
        vector<int>& last = res.back();
        if (last[1] >= item.second) {
          continue;
        } else if (last[1] >= item.first) {
          last[1] = item.second;
        } else {
          res.push_back(vector<int>{item.first, item.second});
        }
      }
    }

    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<int>> intervals{
      {2, 6},
      {1, 3},
      {15, 18},
      {8, 10},
  };
  ic(s.merge(intervals));
  return 0;
}
