/*
 * @lc app=leetcode.cn id=767 lang=cpp
 *
 * [767] 重构字符串
 */
#include <unordered_map>

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  string reorganizeString(string S) {
    unordered_map<char, int> dict;
    for (auto&& c : S) {
      dict[c]++;
    }
    vector<pair<char, int>> vmap;
    for (auto&& item : dict) {
      vmap.push_back(item);
    }

    sort(vmap.begin(), vmap.end(),
         [](const pair<char, int>& x, const pair<char, int>& y) -> int {
           return x.second > y.second;
         });
    if (vmap[0].second > ((S.size() + 1) / 2)) {
      return "";
    }
    string res;
    res.push_back(vmap[0].first);
    vmap[0].second--;
    while (res.size() < S.size()) {
      for (size_t i = 0; i < vmap.size(); i++) {
        if (vmap[i].second == 0) {
          continue;
        }
        if (res.back() == vmap[i].first) {
          continue;
        }
        res.push_back(vmap[i].first);
        vmap[i].second--;
      }
    }

    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  string S = "vvvlo";
  Solution s;
  ic(s.reorganizeString(S));
  return 0;
}
