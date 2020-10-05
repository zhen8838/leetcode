/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include "commom.hpp"

// @lc code=start
class Solution {
 public:
  int reverse(int x) {
    int res = 0;
    int odd;
    int upbound = (INT32_MAX / 10), upodd = INT32_MAX % 10;
    int lowbound = (INT32_MIN / 10), lowodd = INT32_MIN % 10;

    while (x != 0) {
      odd = x % 10;
      x /= 10;
      if ((res > upbound) || (res == upbound && odd > upodd)) {
        return 0;
      }
      if ((res < lowbound) || (res == lowbound && odd < lowodd)) {
        return 0;
      }
      res = res * 10 + odd;  // 此处会造成溢出,因此上面需要检查
    }
    return res;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  int input = 12345;
  auto s = Solution();
  s.reverse(input);
  // for (auto &&i : input) {
  //   cout << i << ' ';
  // }
  cout << endl;
  return 0;
}