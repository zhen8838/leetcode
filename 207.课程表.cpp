/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */
#include <unordered_map>
#include <unordered_set>

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, unordered_set<int>> g;
    int pre;
    for (auto&& pre : prerequisites) {
      if (not g.count(pre[0])) { g[pre[0]].insert(pre[1]); }
      if (not g.count(pre[1])) g[pre[1]] = unordered_set<int>();
    }
    queue<int> q;
    for (auto it = g.begin(); it != g.end();) {
      if (it->second.empty()) {
        q.push(it->first);
        it = g.erase(it);
      } else {
        it++;
      }
    }

    while (q.size()) {
      pre = q.front(), q.pop();
      for (auto it = g.begin(); it != g.end();) {
        if (it->second.count(pre)) { v.erase(pre); }
        if (v.empty()) {
          q.push(k);
          g.erase(k);
        }
      }
    }

    return g.size() == 0;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  // Mat<int> c{{0, 1}, {0, 2}, {1, 2}};
  Mat<int> c{{0, 1}, {0, 2}, {1, 0}};
  Solution s;
  ic(s.canFinish(3, c));
  return 0;
}
