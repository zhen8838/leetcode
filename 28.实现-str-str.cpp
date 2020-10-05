/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int strStr(string haystack, string needle) {
    size_t i = 0, j = 0, n = haystack.size(), m = needle.size();
    if (m == 0) {
      return 0;
    }
    // 双循环速度太慢。
    // for (i = 0; i < n; i++) {
    //   for (j = 0; j < m; j++) {
    //     if (haystack[i + j] != needle[j]) {
    //       break;
    //     }
    //   }
    //   if (j == m) {
    //     return i;
    //   }
    // }
    while (i < n and j < m) {
      if (haystack[i] == needle[j]) {
        j++;
        i++;
      } else {
        i = i - j + 1; // 此处需要回溯一下，避免匹配到一半断裂
        j = 0;
      }
      // pscalr(i, j, haystack[i], needle[j]);
    }
    if (j == m) {
      return i - j;
    }

    return -1;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  string haystack = "hello", needle = "ll";
  auto S = Solution();
  auto res = S.strStr(haystack, needle);
  pscalr(res);

  return 0;
}
