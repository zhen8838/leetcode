/*
 * @lc app=leetcode.cn id=1371 lang=cpp
 *
 * [1371] 每个元音包含偶数次的最长子字符串
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int findTheLongestSubstring(string s) {
    /* 最长递增子序列的增强版,也就是每个dp的状态还需要多保存a,e,i,o,u的个数 */
    int status = 0, ans = 0;
    vector<int> dict(0b100000, -1);  // 初始化都为-1;
    dict[0] = 0;
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      switch (c) {
        case 'a':
          status ^= 0b00001;
          break;
        case 'e':
          status ^= 0b00010;
          break;
        case 'i':
          status ^= 0b00100;
          break;
        case 'o':
          status ^= 0b01000;
          break;
        case 'u':
          status ^= 0b10000;
          break;
        default:
          break;
      }
      if (dict[status] == -1) {
        // 第一次出现这种状态,记录当前串的结束位置
        dict[status] = i + 1;
      } else {
        ans = max(ans, i + 1 - dict[status]);
      }
    }
    return ans;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  string str = "leetcodeisgreat";
  ic(s.findTheLongestSubstring(str));
  return 0;
}
