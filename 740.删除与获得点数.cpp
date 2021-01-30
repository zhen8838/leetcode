/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除与获得点数
 */
#include <numeric>

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int deleteAndEarn(vector<int>& nums) {
    vector<int> dp(10000 + 1, 0);
    for (auto&& num : nums) {
      dp[num] += num;
    }
    // 他这里说取a的话，就要删除a-1和a+1.
    // 换个说法就是取a就不能取a-1和a+1。也就是和打家劫舍一样，不能取相邻的元素。
    int last = 0, cur = 0,t;
    // 对于打家劫舍问题，当前元素的最大值就是，昨天不偷，今天偷 和 昨天偷 的比较。
    for (size_t i = 1; i <= 10000; i++) {
      tie(cur, last) = make_tuple(max(cur, last + dp[i]), cur);
    }

    return cur;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Vec<int> nums{2, 2, 3, 3, 3, 4};
  Solution s;
  ic(s.deleteAndEarn(nums));
  return 0;
}
