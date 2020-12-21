/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  vector<vector<int>> res;
  vector<int> track;

 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    backtrack(nums, 0, nums.size());
    return res;
  }
  void backtrack(vector<int>& nums, int first, int n) {
    if (first == n) {
      res.push_back(track);
      return;
    }
    /*
              []
          +1/    \
          [1]     []
      +2/    \
      [12]   [1]
   +3/    \
  [123]   [12]
    */

    for (size_t i = 0; i < 2; i++) {
      if (i == 0) {
        track.push_back(nums[first]);
        backtrack(nums, first + 1, n);
        track.pop_back();
      } else {
        backtrack(nums, first + 1, n);
      }
    }
  }
  // void backtrack(vector<int>& nums, int first, int n) {
  //   res.push_back(track);
  //   // if (first == n) {
  //   //   return;
  //   // }
  //   for (size_t i = first; i < n; i++) {
  //     track.push_back(nums[i]);
  //     backtrack(nums, i + 1, n);
  //     track.pop_back();
  //   }
  // }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> a = {1, 2, 3};
  IC(s.subsets(a));
  return 0;
}
