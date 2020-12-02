/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int cnt = 0;
    while (n != 0) {
      // pscalr(bitset<32>(n & (n - 1)),bitset<32>(n),bitset<32>((n - 1)));
      cnt++;
      n = n & (n - 1);
      // n-1会向上面依次借位，也就是将下一个最近的1赋值为0.这样就可以&消除
    }
    return cnt;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  auto s = Solution();
  uint32_t n = 0b00000000000000000000000010000000;
  pscalr(s.hammingWeight(n));

  return 0;
}
