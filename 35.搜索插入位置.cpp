/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    /* 搜索插入位置，实际上就是左边的元素都小于target，右边的有元素大于等于target，也就是要找到左边的右端点，用模板二：
     */
    if (nums.empty()) { return 0; }

    int l = 0, r = nums.size() - 1, mid;
    while (l < r) {
      mid = l + (long)r + 1 >> 1;
      if (nums[mid] < target) l = mid;
      else r = mid - 1;
    }
  }
  // 再判断特例，如果第一个元素都大于等于target，那么就在第一个位置插入。
  return nums[l] < target ? l + 1 : l;
}
}
;
// @lc code=end
int main(int argc, char const* argv[]) {
  Vec<int> nums{1, 3};
  Solution s;
  ic(s.searchInsert(nums, 3));
  return 0;
}
