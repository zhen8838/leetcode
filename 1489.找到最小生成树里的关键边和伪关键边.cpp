/*
 * @lc app=leetcode.cn id=1489 lang=cpp
 *
 * [1489] 找到最小生成树里的关键边和伪关键边
 */
#include <numeric>
#include <unordered_map>

#include "commom.hpp"
// @lc code=start

class UnionFind {
 private:
  vector<int> parent;
  vector<int> size;
  int n;
  // 当前连通分量数目

 public:
  int count;
  UnionFind(int _n) : parent(_n), n(_n), size(_n, 1), count(_n) {
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int x) {
    if (x != parent[x]) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  bool isconnect(int x, int y) { return find(x) == find(y); }

  bool merge(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);
    if (rootx == rooty) {
      return false;
    }
    // 都向size大的聚集
    if (size[rootx] < size[rooty]) {
      swap(rootx, rooty);
    }
    parent[rooty] = rootx;
    size[rootx] += size[rooty];
    --count;
    return true;
  }
  ~UnionFind(){};
};

class Solution {
 private:
  unordered_map<int, int> ans;

 public:
  vector<vector<int>> findCriticalAndPseudoCriticalEdges(
      int n, vector<vector<int>>& edges) {
    for (size_t i = 0; i < edges.size(); i++) {
      edges[i].push_back(i);
    }

    sort(edges.begin(), edges.end(),
         [](vector<int>& a, vector<int>& b) { return a[2] < b[2]; });
    UnionFind uf(n);
    int sum = 0;  // 找到最小生成树的一种情况
    for (auto&& edge : edges) {
      if (uf.merge(edge[0], edge[1])) {
        sum += edge[2];
      }
    }
    // 不断加边,去边,找到关键节点
    vector<vector<int>> ans(2);
    for (size_t i = 0; i < edges.size(); i++) {
      uf = UnionFind(n);
      int v = 0;
      for (size_t j = 0; j < edges.size(); j++) {
        if (i != j and uf.merge(edges[j][0], edges[j][1])) {
          v += edges[j][2];
        }
      }
      /* 如果是关键边,那么此时的 v必然大于 sum 或者 不能组成完整的图了 */
      if (uf.count > 1 or (uf.count == 1 and v > sum)) {
        ans[0].push_back(edges[i][3]);
        continue;  // 是关建边了就不可能是伪关建边
      }
      /* 如果是如果是伪关建边,也就是他在的时候,能形成图,且图的权值为最小值 */
      uf = UnionFind(n);
      v = 0;
      uf.merge(edges[i][0], edges[i][1]);
      v += edges[i][2];
      for (size_t j = 0; j < edges.size(); j++) {
        if (i != j and uf.merge(edges[j][0], edges[j][1])) {
          v += edges[j][2];
        }
      }
      if (v == sum) {
        ans[1].push_back(edges[i][3]);
      }
    }

    return ans;
  }
};
// @lc code=end
int main(int argc, char const* argv[]) {
  Mat<int> edges{{0, 1, 1}, {1, 2, 1}, {2, 3, 2}, {0, 3, 2},
                 {0, 4, 3}, {3, 4, 3}, {1, 4, 6}};
  Solution s;
  ic(s.findCriticalAndPseudoCriticalEdges(5, edges));
  return 0;
}
