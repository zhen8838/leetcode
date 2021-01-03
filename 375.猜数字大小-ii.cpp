/*
 * @lc app=leetcode.cn id=375 lang=cpp
 *
 * [375] 猜数字大小 II
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int getMoneyAmount(int n) { return binserach(8, 10); }

  int binserach(int target, int n) {
    int left = 1, right = n, mid, money = 0;
    while (left <= right) {
      mid = (left + right) / 2;
      if (target == mid) {
        return money;
      } else if (target > mid) {
        left = mid + 1;
        money += mid;
      } else if (target < mid) {
        right = mid - 1;
        money += mid;
      }
      ic(target, mid);
    }
    return money;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  ic(s.binserach(8, 10));
  return 0;
}
