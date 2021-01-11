/*
 * @lc app=leetcode.cn id=922 lang=cpp
 *
 * [922] 按奇偶排序数组 II
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  vector<int> sortArrayByParityII(vector<int>& A) {
    int odd = 1, even = 0;
    while (odd < A.size() and even < A.size()) {
      while (odd < A.size() and A[odd] % 2 == 1) {
        odd += 2;
      }
      while (even < A.size() and A[even] % 2 == 0) {
        even += 2;
      }
      if (odd < A.size() and even < A.size()) {
        swap(A[odd], A[even]);
      }
    }
    return A;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> A{4, 2, 5, 7};
  Solution s;
  ic(s.sortArrayByParityII(A));
  return 0;
}
