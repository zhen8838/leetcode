/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  vector<int> plusOne(vector<int> &digits) {
    int add = 1;
    for (int i = digits.size() - 1; i >= 0; i--) {
      digits[i] += add;
      if (digits[i] >= 10) {
        digits[i] = 0;
        add = 1;
      } else {
        add = 0;
      }
      if (add == 0) {
        break;
      }
    }
    if (add == 1) {
      digits.insert(digits.begin(), add);
    }
    return digits;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  vector<int> input = {4, 3, 2, 9};
  auto s = Solution();
  auto out = s.plusOne(input);
  for (auto &&i : out) {
    cout << i << endl;
  }

  return 0;
}
