/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */
#include "commom.hpp"

// @lc code=start
class Solution {
 public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    map<int, int> dict1, dict2;
    for (auto &&i : nums1) {
      if (dict1.find(i) == dict1.end()) {
        dict1[i] = 1;
      } else {
        dict1[i]++;
      }
    }
    for (auto &&i : nums2) {
      if (dict2.find(i) == dict2.end()) {
        dict2[i] = 1;
      } else {
        dict2[i]++;
      }
    }

    vector<int> out;
    for (auto &&item : dict1) {
      auto res = dict2.find(item.first);
      if (res == dict2.end()) {
        continue;
      } else {
        int n = min(res->second, item.second);
        for (size_t i = 0; i < n; i++) {
          out.push_back(item.first);
        }
      }
    }
    return out;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  vector<int> nums1 = {1, 2, 2, 1}, nums2 = {2, 2};
  auto s = Solution();
  auto profit = s.intersect(nums1, nums2);
  for (auto &&i : profit) {
    cout << i << endl;
  }

  return 0;
}
