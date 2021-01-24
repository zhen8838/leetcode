/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  // int removeDuplicates(vector<int>& nums) {
  //   int offset = 0, len = nums.size();
  //   int last = INT_MAX, cnt = 0, cur;
  //   auto s = nums.begin(), e = s + len;
  //   while (s != e) {
  //     cur = *(s - offset);
  //     if (last != cur) {
  //       last = cur;
  //       cnt = 1;
  //     } else {
  //       cnt++;
  //     }
  //     if (cnt > 2) {
  //       nums.erase(s - offset);
  //       cnt--;
  //       offset++;
  //     }
  //     s++;
  //   }
  //   return len - offset;
  // }
  int removeDuplicates(vector<int>& nums) {
    // 去除重复元素中，双指针才是完美解法，考虑到我们就是让每个前面的元素都保持两个，那么我们将多余的元素直接赋值为后面的元素，这样就相当于的将后面的元素提前了
    int k = 2;
    if (nums.size() < 3) {
      return nums.size();
    }
    int slow = k - 1;
    // 2.判断终止条件
    for (int fast = k; fast < nums.size(); fast++) {
      // 3.指针移动条件
      if (nums[fast] != nums[slow - k + 1]) {
        slow++;
        nums[slow] = nums[fast];
      }
    }
    // 4.判断返回值
    return slow + 1;
  }
};
// @lc code=end
