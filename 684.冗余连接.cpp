/*
 * @lc app=leetcode.cn id=684 lang=cpp
 *
 * [684] 冗余连接
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  vector<int> parent;

 public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    for (size_t i = 0; i <= edges.size(); i++) {
      parent.push_back(i);
    }
    vector<int> res;
    for (auto&& edge : edges) {
      int x = edge[0], y = edge[1];
      int rootx = dofind(x);
      int rooty = dofind(y);
      if (rootx == rooty) {
        // 相等说明是冗余的
        return edge;
      }
      // ic(rootx, rooty, x, y);
      parent[rooty] = rootx;
    }
    return {0, 0};
  }

  int dofind(int x) {
    if (x != parent[x]) {
      parent[x] = dofind(parent[x]);
    }
    return parent[x];
  }

  void dounion(int x, int y) {
    int rootx = dofind(x);
    int rooty = dofind(y);
    // ic(rootx, rooty, x, y);
    parent[rooty] = rootx;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  Mat<int> mat{Vec<int>{1, 2}, Vec<int>{2, 3}, Vec<int>{3, 4}, Vec<int>{1, 4},
               Vec<int>{1, 5}};
  ic(s.findRedundantConnection(mat));
  return 0;
}
