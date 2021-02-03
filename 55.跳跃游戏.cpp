/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
// @lc code=start
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int idx = 1, i = 0;
    for (i = 0; i < idx and i < nums.size(); i++) {
      idx = max(idx, i + nums[i] + 1);
    }
    if (idx >= nums.size()) {
      return true;
    }
    return false;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{1, 1, 2, 2, 0, 1, 1};
  Solution s;
  ic(s.canJump(nums));
  return 0;
}
