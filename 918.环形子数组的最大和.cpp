/*
 * @lc app=leetcode.cn id=918 lang=cpp
 *
 * [918] 环形子数组的最大和
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int maxSubarraySumCircular(vector<int>& A) {
    if (A.empty()) {
      return 0;
    }
    int n = A.size(), idx, ansmax = A[0], ansmin = A[0], curmin = A[0],
        curmax = A[0], varmax = A[0], total = A[0];

    // vector<int> dp(n, 0);
    for (size_t i = 1; i < n; i++) {
      curmax = max(A[i], curmax + A[i]);
      curmin = min(A[i], curmin + A[i]);
      ansmax = max(ansmax, curmax);
      ansmin = min(ansmin, curmin);
      varmax = max(varmax, A[i]);
      total += A[i];
      // ic(i, A[i], total, ansmax, ansmin);
    }
    // 如果全是负的元素,那么返回最大元素.
    if (ansmin == total) {
      return ansmax;
    }
    // 否则我们就返回最大值,或者是总数减去ansmin,
    // 就是我们删除中间一段有负数的情况
    return max(ansmax, total - ansmin);
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{-10, -7, 9, -7, 6, 9, -9, -4, -8, -5};
  Solution s;
  ic(s.maxSubarraySumCircular(nums));
  return 0;
}
