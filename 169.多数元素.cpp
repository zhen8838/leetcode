/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    // map<int, int> d;
    // for (auto&& i : nums) {
    //   d[i]++;
    // }
    // for (auto&& item : d) {
    //   if (item.second > nums.size() / 2) {
    //     return item.first;
    //   }
    // }
    // return 0;
    //摩尔投票法，遇到相同的数，就投一票，遇到不同的数，就减一票，最后还存在票的数就是众数

    int count = 0;
    int candidate = 0;
    for (auto&& num : nums) {
      if (count == 0) {
        candidate = num;
      }
      count += (num == candidate) ? 1 : -1;
    }
    return candidate;
  }
};
// @lc code=end
