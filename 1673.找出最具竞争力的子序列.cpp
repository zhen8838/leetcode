/*
 * @lc app=leetcode.cn id=1673 lang=cpp
 *
 * [1673] 找出最具竞争力的子序列
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  vector<int> mostCompetitive(vector<int>& nums, int k) {
    vector<int> res;
    k = nums.size() - k;
    for (size_t i = 0; i < nums.size(); i++) {
      while (k and res.size() and res.back() > nums[i]) {
        res.pop_back();
        k--;
      }
      res.push_back(nums[i]);
    }
    while (k) {
      res.pop_back();
      k--;
    }
    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{2, 4, 3, 3, 5, 4, 9, 6};
  Solution s;
  s.mostCompetitive(nums, 4);
  return 0;
}
