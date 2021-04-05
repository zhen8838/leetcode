/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
 public:
  vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0, r = numbers.size() - 1, mid;
    int start, end;
    for (int i = 0; i < numbers.size() - 1; i++) {
      start = i, l = i + 1, r = numbers.size() - 1;
      while (l < r) {
        mid = l + r >> 1;
        if (numbers[mid] >= (target - numbers[i])) r = mid;
        else
          l = mid + 1;
      }
      end = l;
      if (numbers[end] == (target - numbers[start])) { break; }
    }
    return {start + 1, end + 1};
  }
};
// @lc code=end
