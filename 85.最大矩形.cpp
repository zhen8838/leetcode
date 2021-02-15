/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 */

// @lc code=start
class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) { return 0; }

    int h = matrix.size(), w = matrix[0].size();
    vector<int> dp(w + 2, 0);  // 设置两个哨兵
    stack<int> s;
    int left, cur, right, ans;
    /* 用dp记录当前位置连续1的高度 */
    for (int y = 0; y < h; y++) {
      for (int x = 0; x < w + 2; x++) {
        if (x > 0 and x <= w) {  //只更新哨兵中间的部分
          dp[x] = (matrix[y][x - 1] == '0') ? 0 : (dp[x] + 1);
        }
        while (s.size() and dp[s.top()] > dp[x]) {
          cur = s.top(), s.pop();
          left = s.top() + 1;
          right = x - 1;
          ans = max(ans, dp[cur] * (right - left + 1));
        }
        s.push(x);
      }
    }
    return ans;
  }
};
// @lc code=end
