/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int characterReplacement(string s, int k) {
    // https://pic.leetcode-cn.com/578fc15b7b426eb61dcf1fd73bb87f1511d8733c474797dbb9188b706a219cc5.jpg
    int l = 0, r = 0, max_freq = 0;
    vector<int> cnts(26, 0);
    for (r = 0; r < s.size(); r++) {
      cnts[s[r] - 'A']++;
      max_freq = max(max_freq, cnts[s[r] - 'A']);
      if ((r - l + 1) > (max_freq + k)) {
        cnts[s[l] - 'A']--;
        l++;
      }
    }
    return r - l;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  string str = "ABBBB";
  Solution s;
  ic(s.characterReplacement(str, 1));
  return 0;
}
