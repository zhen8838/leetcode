/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) { return nums; }
    vector<int> ans(n, -1);
    stack<int> s;
    for (int i = 0; i < n * 2; i++) {
      int t = nums[i % n];
      while (s.size() and nums[s.top()] < t) {
        ans[s.top()] = t;
        s.pop();
      }
      // 并不需要遍历到无法更新，只需要遍历一个完整循环即可！
      // if (s.size() and s.top() == i % n) { break; }
      // if (s.size() == n) { break; }
      s.push(i % n);
    }
    return ans;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Vec<int> nums{1, 2, 1};
  Solution s;
  s.nextGreaterElements(nums);
  return 0;
}
