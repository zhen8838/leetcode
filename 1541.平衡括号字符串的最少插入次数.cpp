/*
 * @lc app=leetcode.cn id=1541 lang=cpp
 *
 * [1541] 平衡括号字符串的最少插入次数
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int minInsertions(string s) {
    int left = 0;
    int right = 0;
    int ans = 0;
    for (auto&& c : s) {
      switch (c) {
        case '(':
          if (right) {
            right++;
            ans++;
          }
          left++;
          break;

        case ')':
          right++;
          if (right == 2) {
            if (left == 0) {
              left++;
              ans++;
            }
          }
          break;
        default:
          break;
      }
      if (left >= 1 and right >= 2) {
        left -= 1;
        right -= 2;
      }
    }
    if (left) {
      ans += 2 * left - right;
      right = 0;
    }
    if (right) {
      ans += 2;
    }

    return ans;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution S;
  string s = "";
  ic(S.minInsertions(s));
  return 0;
}
