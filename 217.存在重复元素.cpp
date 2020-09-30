/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
#include "commom.hpp"

// @lc code=start
class Solution {
 public:
  bool containsDuplicate(vector<int> &nums) {
    // vector<int> key = {};
    // vector<int> count = {};
    map<int, int> dict;

    for (auto &&n : nums) {
      if (dict.find(n) == dict.end()) {
        dict[n] = 1;
      } else {
        dict[n]++;
      }
    }
    for (auto &&item : dict) {
      if (item.second > 1) {
        return true;
      }
    }

    return false;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  vector<int> i = {1, 2, 3, 1};
  auto s = Solution();
  auto profit = s.containsDuplicate(i);
  cout << profit << endl;
  return 0;
}
