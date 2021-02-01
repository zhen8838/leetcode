/*
 * @lc app=leetcode.cn id=762 lang=cpp
 *
 * [762] 二进制表示中质数个计算置位
 */
#include <unordered_set>

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int countPrimeSetBits(int L, int R) {
    unordered_set<int> uset = {2,  3,  5,  7,  11, 13,
                               17, 19, 23, 27, 31

    };
    int ans = 0;
    for (int i = L; i <= R; i++) {
      int cnt = 0;
      int n = i;
      while (n != 0) {
        n &= (n - 1);
        cnt++;
      }
      if (uset.count(cnt)) {
        ans++;
      }
    }
    return ans;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  ic(s.countPrimeSetBits(990, 1048));
  return 0;
}
