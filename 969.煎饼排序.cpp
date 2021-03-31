/*
 * @lc app=leetcode.cn id=969 lang=cpp
 *
 * [969] 煎饼排序
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  vector<int> pancakeSort(vector<int>& arr) {
    vector<int> ans;
    int n = arr.size(), s;
    while (n) {
      auto p = max_element(arr.begin(), arr.begin() + n);
      s = p - arr.begin() + 1;
      if (s != n) {
        if (s != 1) {
          reverse(arr.begin(), p + 1);
          ans.push_back(s);
        }
        reverse(arr.begin(), arr.begin() + n);
        ans.push_back(n);
      }
      n--;
    }
    return ans;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) { return 0; }
