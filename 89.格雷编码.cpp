/*
 * @lc app=leetcode.cn id=89 lang=cpp
 *
 * [89] 格雷编码
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  vector<int> grayCode(int n) {
    vector<int> res;
    res.push_back(0);
    int prefix = 1;
    while (n) {
      for (int i = prefix - 1; i >= 0; i--) {
        res.push_back(prefix + res[i]);
      }
      prefix *= 2;
      n--;
    }

    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  ic(s.grayCode(3));
  return 0;
}
