/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    // 下标的差值是不大于k的，也就是在一个滑动窗口里面寻找值即可
    if (nums.empty()) { return false; }
    set<long long> uset;
    for (int l = 0, r = 0; r < nums.size() - 1; r++) {
      uset.insert(nums[r]);
      while (r - l >= k) { uset.erase(nums[l++]); }
      // 找到距离r+1最近的两个元素：
      auto lp = uset.lower_bound((long long)nums[r + 1] - t);
      // 假设现在是9，我们要找的数字是
      // 大于等于7的第一个元素。那么他只有两种情况了，
      if (lp != uset.end() and abs(*lp - (long long)nums[r + 1]) <= t) {
        // ic(*lp, nums[r + 1]);
        return true;
      }
    }
    return false;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums{1, 5, 9, 1, 5, 9};
  int k = 2, t = 3;
  ic(s.containsNearbyAlmostDuplicate(nums, k, t));
  return 0;
}
