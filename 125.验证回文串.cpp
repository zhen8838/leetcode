/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool isPalindrome(string s) {
    int i = 0, j = s.size() - 1;
    char ic, jc;

    while (i < j) {  // 其实我们只需要对比一半就好了，因为另一半已经对比完成了
      while ((not isalnum(s[i])) and (i < j)) {
        i++;
        // pscalr(i);
      }
      while (not isalnum(s[j]) and (i < j)) {
        j--;
        // pscalr(j);
      }
      if (i < j) {
        ic = tolower(s[i]);
        jc = tolower(s[j]);
        if (ic != jc) return false;
        i++;
        j--;
      }
    }
    return true;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  string str = "0P";
  auto s = Solution();
  auto out = s.isPalindrome(str);
  pscalr(out);
  return 0;
}
