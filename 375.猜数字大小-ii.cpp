/*
 * @lc app=leetcode.cn id=375 lang=cpp
 *
 * [375] 猜数字大小 II
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int getMoneyAmount(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    // if only two number, wo must choice smaller number
    // because if we guess wrong, we will cost less;
    for (size_t i = 1; i < n; i++) {
      dp[i][i + 1] = i;
    }
    // why we need reverse ?
    for (int low = n - 2; low > 0; low--) {
      // why we need reverse ?
      for (int high = low + 2; high < n + 1; high++) {
        int minval = INT_MAX;
        for (int x = low; x < high; x++) {
          minval = min(minval, x + max(dp[low][x - 1], dp[x + 1][high]));
          // ic(low, high, x, dp[low][x - 1], dp[x + 1][high]);
        }
        dp[low][high] = minval;
        // ic(dp);
      }
    }
    return dp[1][n];
  }

  // int binserach(int target, int n) {
  //   int left = 1, right = n, mid, money = 0;
  //   while (left <= right) {
  //     mid = (left + right) / 2;
  //     if (target == mid) {
  //       return money;
  //     } else if (target > mid) {
  //       left = mid + 1;
  //       money += mid;
  //     } else if (target < mid) {
  //       right = mid - 1;
  //       money += mid;
  //     }
  //     ic(target, mid);
  //   }
  //   return money;
  // }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  ic(s.getMoneyAmount(10));
  return 0;
}
