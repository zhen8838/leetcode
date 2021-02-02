/*
 * @lc app=leetcode.cn id=888 lang=cpp
 *
 * [888] 公平的糖果交换
 */
#include <numeric>

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    int asum = accumulate(A.begin(), A.end(), 0),
        bsum = accumulate(B.begin(), B.end(), 0);
    sort(B.begin(), B.end());

    for (int i = 0; i < A.size(); i++) {
      int target = (2 * A[i] + bsum - asum) / 2;
      if (binary_search(B.begin(), B.end(), target)) {
        return {A[i], target};
      }
    }
    return {0, 0};
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Vec<int> a{1, 1}, b{2, 2};
  Solution s;
  ic(s.fairCandySwap(a, b));
  return 0;
}
