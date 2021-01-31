/*
 * @lc app=leetcode.cn id=813 lang=cpp
 *
 * [813] 最大平均值和的分组
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  double largestSumOfAverages(vector<int>& A, int K) {
    double ans, mean;
    int n = A.size();
    for (size_t i = 1; i < n; i++) {
      A[i] += A[i - 1];
    }
    vector<vector<double>> dp(K + 1, vector<double>(n, 0.));

    // dp[i][k]是第i个位置切第k刀。
    // 比如我们要分三组得到最大值，假设从[0~j]是一二组，从[j~n]为第三组。 满足
    // mean([0~j])+mean([j~k])最大

    // 那么从[0~k] [k~j]分别为1，2组，他们也满足
    // mean([0~k])+mean([k~j])最大，那么就分解成子问题了，即我们每个位置的最大值是
    // 切上一刀的位置到这一刀的位置的 两组和最大
    // 对于切一刀的情况，永远都是均值。
    for (int i = 0; i < n; i++) {
      dp[1][i] = (double)A[i] / (i + 1);
      for (int k = 2; k <= K; k++) {
        for (int j = 0; j < i; j++) {
          double mean = ((double)(A[i] - A[j]) / (i - j));
          dp[k][i] = max(dp[k][i], dp[k - 1][j] + mean);
        }
      }
    }
    return dp[K][n - 1];
  }
};
// @lc code=end
