/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  void reverseString(vector<char> &s) {
    int n = s.size();
    for (size_t i = 0; i < (n / 2); i++) {
      swap(s[i], s[n - i - 1]);
    }
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  vector<char> input = {'h', 'e', 'l', 'l', 'o'};
  auto s = Solution();
  s.reverseString(input);
  for (auto &&i : input) {
    cout << i << ' ';
  }
  cout << endl;
  return 0;
}
