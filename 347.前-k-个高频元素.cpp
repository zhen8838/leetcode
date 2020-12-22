/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> cnt;
    for (auto&& num : nums) {
      cnt[num]++;
    }

    multimap<int, int, greater<int>> recnt;
    for (auto&& item : cnt) {
      // recnt[item.second] = item.first;
      recnt.emplace(item.second, item.first);
    }
    // IC(cnt);
    // IC(recnt);

    vector<int> res;
    auto p = recnt.begin();
    for (size_t i = 0; i < k; i++) {
      res.push_back(p->second);
      p++;
    }

    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{-1, -1};
  int k = 1;
  Solution s;
  IC(s.topKFrequent(nums, k));
  return 0;
}
