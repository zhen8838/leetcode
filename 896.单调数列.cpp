/*
 * @lc app=leetcode.cn id=896 lang=cpp
 *
 * [896] 单调数列
 */

// @lc code=start
class Solution {
 public:
  bool isMonotonic(vector<int>& A) {
    int diff = 0;
    for (int i = 1; i < A.size(); i++) {
      if (A[i - 1] == A[i]) continue;
      else if (A[i - 1] > A[i]) {
        if (diff == 0) diff = -1;
        else if (diff == 1) {
          return false;
        }
      } else {
        if (diff == 0) diff = 1;
        else if (diff == -1) {
          return false;
        }
      }
    }
    return true;
  }
};
// @lc code=end
