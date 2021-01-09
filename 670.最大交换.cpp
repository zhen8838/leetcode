/*
 * @lc app=leetcode.cn id=670 lang=cpp
 *
 * [670] 最大交换
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int maximumSwap(int num) {
    string snum = to_string(num);
    for (size_t i = 0; i < snum.size() - 1; i++) {
      char maxval = *max_element(snum.begin() + i + 1, snum.end());
      // ic(snum[i],maxval);
      if (snum[i] < maxval) {
        auto found = snum.find_last_of(maxval);
        swap(snum[i], snum[found]);
        break;
      }
    }
    return stoi(snum);
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  s.maximumSwap(2736);
  return 0;
}
