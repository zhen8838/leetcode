/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> res;
    while (rowIndex-- + 1) {
      res.push_back(1);
      for (int i = res.size() - 2; i >= 1; i--) {
        res[i] += res[i - 1];
      }
    }
    return res;
  }
};
// @lc code=end
