/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int findLength(vector<int>& A, vector<int>& B) {
    // 动态规划法
    int h = A.size(), w = B.size();
    vector<vector<int>> dp(h, vector<int>(w, 0));
    // 当匹配到相同值后，向[y+1][x+1]的方向继续搜索。
    int res = 0;
    for (size_t y = 0; y < h; y++) {
      for (size_t x = 0; x < w; x++) {
        if (A[y] == B[x]) {
          if (y > 0 and x > 0) {
            dp[y][x] = dp[y - 1][x - 1] + 1;
          } else {
            dp[y][x] = 1;
          }
          res = max(res, dp[y][x]);
        }
      }
      // ic(dp);
    }
    return res;
  }
  // int findLength(vector<int>& A, vector<int>& B) {
  //   return A.size() < B.size() ? findmax(A, B) : findmax(B, A);
  // }

  int findmax(vector<int>& A, vector<int>& B) {
    /* A是短的，B是长的 */
    int res = 0;
    int an = A.size(), bn = B.size();
    for (int n = 1; n < an; n++) {  // A进入
      if (res >= n) {
        continue;
      }
      res = max(res, maxlen(A, B, 0, bn - n, n));
    }
    for (int i = bn - an; i >= 0; i--) {  // A在B内部
      if (res >= an) {
        continue;
      }
      res = max(res, maxlen(A, B, 0, i, an));
    }
    for (int i = 1; i < an; i++) {  // A退出
      if (res >= (an - i)) {
        continue;
      }
      res = max(res, maxlen(A, B, i, 0, an - i));
    }
    return res;
  }

  int maxlen(vector<int>& A, vector<int>& B, int a, int b, int n) {
    int cnt = 0, res = 0;
    for (int i = 0; i < n; i++) {
      if (A[a + i] == B[b + i]) {
        cnt++;
      } else if (cnt > 0) {
        res = max(res, cnt);
        cnt = 0;
      }
    }
    return max(cnt, res);
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Vec<int> a{1, 2, 3, 2, 1}, b{3, 2, 1, 4, 7};
  Solution s;
  ic(s.findLength(a, b));
  return 0;
}
