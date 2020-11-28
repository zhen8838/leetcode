/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

#include "commom.hpp"

// @lc code=start
class Solution {
 public:
  int countPrimes(int n) {
    // 节省空间就是逐步判断
    // int cnt = 0;
    // for (size_t i = 0; i < n; i++) {
    //   if (this->isPrimes(i)) {
    //     cnt++;
    //   }
    // }
    // return cnt;
    // 节省时间用跳跃删选
    int cnt = 0;

    if (n == 0 || n == 1) {
      return cnt;
    }
    /* 数组需要多开一个 */
    int* arr = new int[n + 1];

    for (size_t i = 0; i < n; i++) {
      if (i < 2) {
        arr[i] = 0;
      } else {
        arr[i] = 1;
      }
    }
    /* 数组需要多开一个 */
    for (size_t i = 2; i <= n / i; i++) {
      if (arr[i]) {
        for (size_t j = 2; j <= n / i; j++) {
          arr[i * j] = 0;
        }
      }
    }

    for (size_t i = 0; i < n; i++) {
      if (arr[i]) {
        cnt++;
      }
    }

    return cnt;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s = Solution();
  cout << s.countPrimes(10) << endl;
  return 0;
}
