/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  int maxans = 0;

 public:
  int rob(vector<int>& nums) {
    vector<int> memo(nums.size(), -1);
    dfs(memo, nums, 0, 0, nums.size());
    return maxans;
  }
  void dfs(vector<int>& memo, vector<int>& nums, int ans, int first, int len) {
    // ic(first, ans);
    if (first >= len) {
      // 如果偷完了那么统计当前结果
      maxans = max(maxans, ans);
      return;
    }
    // 剪枝,只有我们在当前位置有更好的偷法,那就继续偷,否则需要换一种方法.
    if (ans > memo[first]) {
      memo[first] = ans;
      // 偷当前房间，那么下次隔一间房开始偷
      dfs(memo, nums, ans + nums[first], first + 2, len);
      // 不偷当前房间，那么下次从下一间房开始偷
      dfs(memo, nums, ans, first + 1, len);
    }
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{104, 209, 137, 52,  158, 67,  213, 86,  141, 110,
                   151, 127, 238, 147, 169, 138, 240, 185, 246, 225,
                   147, 203, 83,  83,  131, 227, 54,  78,  165, 180,
                   214, 151, 111, 161, 233, 147, 124, 143};
  Solution s;
  ic(s.rob(nums));
  return 0;
}
