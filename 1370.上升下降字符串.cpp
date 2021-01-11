/*
 * @lc app=leetcode.cn id=1370 lang=cpp
 *
 * [1370] 上升下降字符串
 */
#include <unordered_map>

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  string sortString(string s) {
    unordered_map<char, int> freq;
    for (auto&& c : s) {
      freq[c]++;
    }
    vector<pair<char, int>> vfreq;
    for (auto&& item : freq) {
      vfreq.push_back(item);
    }

    sort(vfreq.begin(), vfreq.end(),
         [](pair<char, int>& a, pair<char, int>& b) {
           return a.first < b.first;
         });
    string s1;
    while (s1.size() != s.size()) {
      for (auto&& item : vfreq) {
        if (item.second > 0) {
          s1.push_back(item.first);
          item.second--;
        }
      }
      // ic(s1);
      for (int i = vfreq.size() - 1; i >= 0; i--) {
        if (vfreq[i].second > 0) {
          s1.push_back(vfreq[i].first);
          vfreq[i].second--;
        }
      }
      // ic(s1);
    }
    return s1;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  string s = "leetcode";
  Solution S;
  S.sortString(s);
  return 0;
}
