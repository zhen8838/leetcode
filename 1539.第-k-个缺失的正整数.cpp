/*
 * @lc app=leetcode.cn id=1539 lang=cpp
 *
 * [1539] 第 k 个缺失的正整数
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int findKthPositive(vector<int>& arr, int k) {
    int p = 0, i = 1;
    while (k) {
      if (p < arr.size()) {
        if (arr[p] == i) {
          p++;
        } else {
          k--;
        }
      } else {
        k--;
      }
      i++;
    }
    return i - 1;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  auto s = Solution();

  auto arr = vector<int>({2, 3, 4, 7, 11});
  IC(s.findKthPositive(arr, 5));
  return 0;
}
