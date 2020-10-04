/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include "commom.hpp"

// @lc code=start
class Solution {
 public:
  vector<int> twoSum(vector<int> &nums, int target) {
    // sort(nums.begin(), nums.end());
    // int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    int end = nums.size();
    for (int i = 0; i < end; i++) {
      for (int j = i + 1; j < end; j++) {
        if ((nums[i] + nums[j]) == target) {
          return vector<int>({i, j});
        }
      }
    }

    return nums;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  vector<int> input = {11, 15, 2, 7};
  int target = 9;
  auto s = Solution();
  auto out = s.twoSum(input, target);
  for (auto &&i : out) {
    cout << i << endl;
  }

  return 0;
}
