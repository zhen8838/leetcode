/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    int i = 0, j = -1;
    for (size_t p = 0; p < nums.size(); p++) {
      if (nums[p] <= nums[i]) {
        i = p;
      } else {
        if (j == -1) {
          j = p;
        } else {
          if (nums[p] <= nums[j]) {
            j = p;
          } else {
            return true;
          }
        }
      }
    }
    return false;
  }
};
// @lc code=end
int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> v({1, 2, 2, 1});
  IC(s.increasingTriplet(v));
  return 0;
}
