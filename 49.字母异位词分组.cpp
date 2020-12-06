/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    map<string, vector<int>> dict;
    for (size_t i = 0; i < strs.size(); i++) {
      auto str = strs[i];
      sort(str.begin(), str.end());
      dict[str].push_back(i);
    }
    vector<vector<string>> res;
    for (auto&& item : dict) {
      vector<string> tmp;
      for (auto&& i : item.second) {
        tmp.push_back(strs[i]);
      }
      res.push_back(tmp);
    }
    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  auto s = Solution();
  vector<string> strs({"eat", "tea", "tan", "ate", "nat", "bat"});
  auto res = s.groupAnagrams(strs);
  for (auto&& row : res) {
    IC(row);
  }

  return 0;
}
