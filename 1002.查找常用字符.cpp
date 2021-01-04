/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 */

// @lc code=start
class Solution {
 public:
  vector<string> commonChars(vector<string>& A) {
    vector<vector<int>> mat(A.size(), vector<int>(26, 0));
    for (size_t i = 0; i < A.size(); i++) {
      for (size_t j = 0; j < A[i].size(); j++) {
        mat[i][A[i][j] - 'a']++;
      }
    }
    int count = 0;
    vector<string> res;
    for (uint8_t j = 0; j < 26; j++) {
      count = mat[0][j];
      for (uint8_t i = 1; i < A.size(); i++) {
        count = min(count, mat[i][j]);
        if (count == 0) {
          break;
        }
      }
      for (uint8_t k = 0; k < count; k++) {
        res.push_back(string(1, 'a' + j));
      }
    }
    return res;
  }
};
// @lc code=end
