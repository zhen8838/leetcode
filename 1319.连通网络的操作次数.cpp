/*
 * @lc app=leetcode.cn id=1319 lang=cpp
 *
 * [1319] 连通网络的操作次数
 */
#include <numeric>
#include <unordered_set>

#include "commom.hpp"
// @lc code=start
class UnionFind {
 public:
  vector<int> parent;
  UnionFind(int _n) : parent(_n) { iota(parent.begin(), parent.end(), 0); };

  int find(int x) {
    if (x != parent[x]) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  bool merge(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);
    if (rootx == rooty) {
      return false;
    }
    parent[rooty] = rootx;
    return true;
  }
};

class Solution {
 public:
  int makeConnected(int n, vector<vector<int>>& connections) {
    UnionFind uf(n);
    unordered_set<int> uset;
    int count = 0;
    for (size_t i = 0; i < connections.size(); i++) {
      if (not uf.merge(connections[i][0], connections[i][1])) {
        count++;
      }
    }
    for (size_t i = 0; i < n; i++) {
      uset.emplace(uf.find(i));
    }
    if (count >= (uset.size() - 1)) {
      return uset.size() - 1;
    }
    return -1;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  Mat<int> conn{{1, 5}, {1, 7}, {1, 2}, {1, 4}, {3, 7}, {4, 7}, {3, 5},
                {0, 6}, {0, 1}, {0, 4}, {2, 6}, {0, 3}, {0, 2}};
  ic(s.makeConnected(12, conn));
  return 0;
}
