/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */
#include <unordered_set>

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // 这个graph没必要开这么大
    vector<vector<int>> g(numCourses);
    for (auto&& pre : prerequisites) {
      g[pre[0]].push_back(pre[1]);
    }
    // track 没必要用set
    // unordered_set<int> track;
    vector<int> track(numCourses, 0);
    // ic(g);
    bool res = true;
    for (size_t i = 0; i < numCourses; i++) {
      track[i] = 1;
      res &= dfs(g, track, i);
      track[i] = 0;
    }

    return res;
  }

  bool dfs(vector<vector<int>>& g, vector<int>& track, int i) {
    bool res = true;
    if (g[i].empty()) {
      return res;
    }

    for (int j = g[i].size() - 1; j >= 0; j--) {
      int next = g[i][j];
      if (track[next]) {
        return false;
      }
      track[next] = 1;
      // ic(i,j,track);
      res &= dfs(g, track, next);
      g[i].pop_back();  //删除这个节点,避免重复遍历
      track[next] = 0;
    }
    return res;
  }

  // int find(int x) {
  //   if (x != parent[x]) {
  //     parent[x] = find(parent[x]);
  //   }
  //   return parent[x];
  // }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  // Mat<int> c{{0, 1}, {0, 2}, {1, 2}};
  Mat<int> c{{0, 1}, {0, 2}, {1, 0}};
  Solution s;
  ic(s.canFinish(3, c));
  return 0;
}
