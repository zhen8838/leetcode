/*
 * @lc app=leetcode.cn id=1027 lang=cpp
 *
 * [1027] 最长等差数列
 */
#include <unordered_map>

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int longestArithSeqLength(vector<int>& A) {
    int n = A.size(), last, diff, ans = 0;
    vector<vector<int>> dp(n, vector<int>(10000 * 2 + 1, 0));

    for (int e = 1; e < n; e++) {
      for (int s = 0; s < e; s++) {
        diff = A[e] - A[s] + 10000;
        // ic(A[e], A[s], dp[e][diff], dp[s][diff]);
        // 一定要先判断起点是不是0
        if (dp[s][diff] == 0) {
          dp[e][diff] = 2;
        } else {
          // 以当前数e结尾且与上一个数差值为diff， 上一个状态即dp[s][diff]；
          dp[e][diff] = max(dp[e][diff], dp[s][diff] + 1);
        }
        ans = max(ans, dp[e][diff]);
      }
    }
    return ans;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Vec<int> nums{3, 6, 9, 12};
  Solution s;
  ic(s.longestArithSeqLength(nums));
  return 0;
}
