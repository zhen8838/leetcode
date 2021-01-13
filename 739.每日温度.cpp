/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  vector<int> dailyTemperatures(vector<int>& T) {
    stack<vector<int>> s;
    vector<int> res(T.size(), 0);
    s.push(vector<int>{T[0], 0});
    for (int i = 1; i < T.size(); i++) {
      int cur = T[i];
      while (s.size() and cur > s.top()[0]) {
        res[s.top()[1]] = i - s.top()[1];
        s.pop();
      }
      s.push(vector<int>{cur, i});
    }
    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Vec<int> T{73, 74, 75, 71, 69, 72, 76, 73};
  Solution s;
  ic(s.dailyTemperatures(T));
  return 0;
}
