/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    auto mat = vector<vector<int>>();
    vector<int>*last = nullptr, *cur = nullptr;
    if (numRows == 0) return mat;
    for (size_t i = 0; i < numRows; i++) {
      cur = new vector<int>(i + 1, 1);
      if (last != nullptr) {
        for (size_t j = 1; j < i; j++) {
          cur->at(j) = last->at(j - 1) + last->at(j);
        }
      }
      mat.push_back(*cur);
      last = cur;
    }
    return mat;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  auto s = Solution();
  int n = 5;
  auto mat = s.generate(n);
  for (size_t i = 0; i < mat.size(); i++) {
    pvec<int>(mat[i]);
  }

  return 0;
}
