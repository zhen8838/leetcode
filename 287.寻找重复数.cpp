/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    // 快慢指针永远的神,当前快慢指针相遇时,从头开始遍历与慢指针的相遇的位置即为入口!
    int slow = 0, fast = 0;
    while (true) {
      slow = nums[slow];
      fast = nums[nums[fast]];
      if (slow == fast) {
        break;
      }
    }
    // ic(slow, fast);
    int find = 0;
    while (find != slow) {
      find = nums[find];
      slow = nums[slow];
    }
    return find;

    // int ans;
    // auto cmp = [&ans](int a, int b) {
    //   if (a == b) {
    //     ans = a;
    //   }
    //   return a < b;
    // };
    // sort(nums.begin(), nums.end(), cmp);
    // return ans;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{3,1,3,4,2};
  Solution s;
  ic(s.findDuplicate(nums));
  return 0;
}
