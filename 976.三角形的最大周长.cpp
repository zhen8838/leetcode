/*
 * @lc app=leetcode.cn id=976 lang=cpp
 *
 * [976] 三角形的最大周长
 */
#include <algorithm>
#include <vector>

#include "icecream.hpp"
using namespace std;

// @lc code=start
class Solution {
 public:
  int largestPerimeter(vector<int>& A) {
    if (A.size() < 3) {
      return 0;
    }

    sort(A.begin(), A.end(), greater<int>());
    int a, b, c;
    for (size_t i = 0; i < A.size() - 2; i++) {
      a = A[i + 0];
      b = A[i + 1];
      c = A[i + 2];
      if (b + c > a) {
        break;
      }
    }

    if (b + c > a) {
      return a + b + c;
    }
    return 0;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> A{2, 1, 2};
  IC(s.largestPerimeter(A));
  IC(A);
  return 0;
}
