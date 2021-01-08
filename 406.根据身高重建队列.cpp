/*
 * @lc app=leetcode.cn id=406 lang=cpp
 *
 * [406] 根据身高重建队列
 */
#include "commom.hpp"

// @lc code=start
class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
      if (a[0] == b[0]) {
        return a[1] < b[1];
      }
      return a[0] > b[0];
    });
    // 先按身高从高到低,然后他前面的人个数k从低到高.直接按k插入即可.
    vector<vector<int>> ans;
    for (auto&& item : people) {
      ans.insert(ans.begin() + item[1], item);
    }
    return ans;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<vector<int>> people{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
  Solution s;
  ic(s.reconstructQueue(people));
  return 0;
}
