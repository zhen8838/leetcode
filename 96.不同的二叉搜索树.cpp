/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int numTrees(int n) {
    // 卡特兰数
    // 2n!/(n+1)!
    long long C = 1;
    for (int i = 0; i < n; ++i) {
      C = C * 2 * (2 * i + 1) / (i + 2);
    }
    return (int)C;
  }
};
// @lc code=end
