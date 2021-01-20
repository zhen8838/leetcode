/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */
#include <unordered_map>

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C,
                   vector<int>& D) {
    int count = 0;
    /* 将四数相加转换为两数相加的问题
      0 - A+B = (C+D)
      遍历A+B,存为0-(A+B)则匹配(C+D)
     */
    unordered_map<int, int> ab;
    for (size_t i = 0; i < A.size(); i++) {
      for (size_t j = 0; j < B.size(); j++) {
        ab[0 - A[i] - B[j]]++;
      }
    }
    for (size_t i = 0; i < C.size(); i++) {
      for (size_t j = 0; j < D.size(); j++) {
        // 这里因为map默认就是给的0,所以直接加就好了,不过会生成额外的插入操作,还是先判断一下比较快.
        if (ab.count(C[i] + D[j])) {
          count += ab[C[i] + D[j]];
        }
      }
    }
    return count;
  }
};
// @lc code=end
