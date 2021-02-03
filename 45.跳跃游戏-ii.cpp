/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
 public:
  int jump(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
      return 0;
    }
    int last = 0, next = nums[0], cnt = 1;

    for (int i = 1; i < n; i++) {
      if (next >= n - 1) {
        break;
      }
      if (next < i + nums[i]) {
        if (i > last) {
          cnt++;
          last = next;
        }
        next = i + nums[i];
      }
    }
    return cnt;
  }
};
// @lc code=end
