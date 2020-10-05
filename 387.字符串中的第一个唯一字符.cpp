/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int firstUniqChar(string s) {
    map<char, int> dict;
    vector<char> out;

    for (size_t i = 0; i < s.size(); i++) {
      dict[s[i]] += 1;
    }
    for (size_t i = 0; i < s.size(); i++) {
      if (dict[s[i]] == 1) {
        return i;
      }
    }

    // for (auto &&item : dict) {
    //   cout << item.first << ' ' << item.second << endl;
    // }

    return -1;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  string str("loveleetcode");
  auto s = Solution();
  int i = s.firstUniqChar(str);
  cout << i << endl;
  return 0;
}
