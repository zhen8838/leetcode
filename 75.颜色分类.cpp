/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  void sortColors(vector<int>& nums) {
    vector<int> idx(3, -1);
    size_t n = nums.size();
    for (size_t i = 0; i < n; i++) {
      // 如果没有值，就赋值
      if (idx[nums[i]] == -1) {
        idx[nums[i]] = i;
      };
      int cur = i, tmp = nums[i];
      // 当前元素的索引值必须要小于 "大于当前元素的其他元素的起始索引"。
      for (size_t j = 3 - 1; j > tmp; j--) {
        // 如果其他元素还没有起始位置就跳过
        if (idx[j] == -1) {
          continue;
        }
        // 如果当前元素位置大于了其他元素
        if (cur > idx[j]) {
          // 交换两个值
          swap(nums[cur], nums[idx[j]]);
          cur = idx[j];  // 更新当前的索引位置
          if (cur < idx[tmp]) {
            // 如果交换之后，新位置比之前当前元素的起始位置小，那么更新起始位置
            idx[tmp] = cur;
          }

          idx[j]++;  // 被交换的元素的起始位置向后挪一位
        }
      }
      // IC(idx, nums);

      // if (nums[i] > nums[i + 1]) {
      //   swap(nums[i], nums[i + 1]);
      // }
    }
    // nums.rev(nums.size());
    // reverse(nums.begin(), nums.end());
    // IC(nums);
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums = {2, 0, 2, 1, 1, 0};
  Solution s;
  s.sortColors(nums);
  return 0;
}