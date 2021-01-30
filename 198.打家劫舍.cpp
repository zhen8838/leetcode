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
    if (nums.empty()) {
      return 0;
    }

    /* 每天的状态是偷和不偷 */
    int a = nums[0];
    int b = 0;
    int lasta, lastb;
    for (size_t i = 1; i < nums.size(); i++) {
      lasta = a;
      lastb = b;
      // 偷，那么昨天不偷的最大值加上今天值。
      a = lastb + nums[i];
      // 不偷，那么昨天偷的最大值与昨天不偷最大值取较大的。
      b = max(lasta, lastb);
    }
    return max(a, b);
  }
  // int rob(vector<int>& nums) {
  //   vector<int> memo(nums.size(), -1);
  //   dfs(memo, nums, 0, 0, nums.size());
  //   return maxans;
  // }
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
  vector<int> nums{2, 7, 9, 3, 1};
  Solution s;
  ic(s.rob(nums));
  return 0;
}
