/*
 * @lc app=leetcode.cn id=1652 lang=cpp
 *
 * [1652] 拆炸弹
 */

// @lc code=start
class Solution {
 public:
  vector<int> decrypt(vector<int>& code, int k) {
    vector<int> arr(code.size(), 0);
    int ni;
    if (k == 0) return arr;
    for (int i = 0; i < arr.size(); i++) {
      for (int j = 0; j < abs(k); j++) {
        if (k > 0) ni = (i + j + 1) % code.size();
        else
          ni = i - j - 1;
        if (ni < 0) { ni += code.size(); }
        arr[i] += code[ni];
      }
    }

    return arr;
  }
};
// @lc code=end
