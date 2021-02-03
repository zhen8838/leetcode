/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    int cnt = 1, last, next;
    if (nums.size() < 2) {
      return nums.size();
    }
    last = 0;
    for (int i = 1; i < nums.size(); i++) {
      next = nums[i] - nums[i - 1];
      if ((last > 0 and next < 0) or (last < 0 and next > 0)) {
        last = next;
        cnt++;
      } else if (last > 0 and next > 0 and next > last) {
        last = next;
      } else if (last < 0 and next < 0 and next < last) {
        last = next;
      } else if (last == 0 and next != 0) {
        last = next;
        cnt++;
      }
    }
    return cnt;
  }
};
// @lc code=end
