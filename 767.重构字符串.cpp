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
    vector<pair<char, int>> vmap(dict.begin(), dict.end());
    sort(vmap.begin(), vmap.end(),
         [](const pair<char, int>& x, const pair<char, int>& y) -> int {
           return x.second < y.second;
         });

    if (vmap.back().second > ((S.size() + 1) / 2)) {
      return "";
    }

    string res(S.size(), ' ');
    int even = 1, odd = 0;
    while (odd < res.size()) {
      if (vmap.back().second == 0) {
        vmap.pop_back();
      }
      res[odd] = vmap.back().first;
      vmap.back().second--;
      odd += 2;
    }
    while (even < res.size()) {
      if (vmap.back().second == 0) {
        vmap.pop_back();
      }
      res[even] = vmap.back().first;
      vmap.back().second--;
      even += 2;
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
