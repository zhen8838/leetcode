/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int longestOnes(vector<int>& A, int K) {
    int l = 0, r = 0, ans = 0, cur = 0;
    while (r < A.size()) {
      if (A[r++] == 1) {
        cur++;
      }
      if ((r - l) - cur > K) {
        cur += A[l++] ? -1 : 0;
      } else {
        ans = max(r - l, ans);
      }
    }
    return ans;
  }
};
// @lc code=end
