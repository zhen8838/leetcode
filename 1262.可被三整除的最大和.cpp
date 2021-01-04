/*
 * @lc app=leetcode.cn id=1262 lang=cpp
 *
 * [1262] 可被三整除的最大和
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  int maxsum = 0;

 public:
  int maxSumDivThree(vector<int>& nums) {
    // ans[0],ans[1],ans[2]分别保存遍历过的元素的和中%3==0，%3==1，%3==2的最大值
    vector<int> ans(3, 0), tmp(3, 0);
    ans[1] = INT_MIN;
    ans[2] = INT_MIN;
    for (auto&& num : nums) {
      if (num % 3 == 0) {
        // 表示当前值,当前值有三种状态,如果当前值能被三整除,那么每个状态加上当前值都是原来的状态
        ans[0] += num;
        ans[1] += num;
        ans[2] += num;
      } else if (num % 3 == 1) {
        // 如果当前值能除三余1,那么 状态0+num,
        // 和状态1我们选大的那个,其他两个类似
        tmp[0] = max(ans[2] + num, ans[0]);
        tmp[1] = max(ans[0] + num, ans[1]);
        tmp[2] = max(ans[1] + num, ans[2]);
        ans = tmp;
      } else if (num % 3 == 2) {
        tmp[0] = max(ans[1] + num, ans[0]);
        tmp[1] = max(ans[2] + num, ans[1]);
        tmp[2] = max(ans[0] + num, ans[2]);
        ans = tmp;
      }
    }
    return ans[0];
  }

  void dfs(vector<int>& nums, int sum, int pos, int len) {
    if (sum % 3 == 0) {
      maxsum = max(maxsum, sum);
    }
    // ic(pos, sum);
    if (pos == len) {
      return;
    }

    dfs(nums, sum + nums[pos], pos + 1, len);
    dfs(nums, sum, pos + 1, len);
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{2, 14, 15, 17};
  Solution s;
  ic(s.maxSumDivThree(nums));
  return 0;
}
