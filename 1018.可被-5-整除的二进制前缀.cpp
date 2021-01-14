/*
 * @lc app=leetcode.cn id=1018 lang=cpp
 *
 * [1018] 可被 5 整除的二进制前缀
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  vector<bool> prefixesDivBy5(vector<int>& A) {
    vector<bool> res;
    int m = 0;
    for (size_t i = 0; i < A.size(); i++) {
      // ic((m << 1) + A[i]);
      m = ((m << 1) + A[i]) % 5;

      res.push_back(m == 0);
    }
    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  Vec<int> A{0, 1, 1, 1, 0, 1, 1};
  s.prefixesDivBy5(A);
  return 0;
}
