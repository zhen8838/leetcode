/*
 * @lc app=leetcode.cn id=778 lang=cpp
 *
 * [778] 水位上升的泳池中游泳
 */
#include <numeric>

#include "commom.hpp"
// @lc code=start
class UnionFind {
 private:
  vector<int> parent;

 public:
  UnionFind(int _n) : parent(_n) { iota(parent.begin(), parent.end(), 0); }

  int find(int x) { return x == parent[x] ? parent[x] : find(parent[x]); }

  void merge(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);
    if (rootx == rooty) {
      return;
    }
    parent[rooty] = rootx;
  }
  bool isconnect(int x, int y) { return find(x) == find(y); }
};

struct Edge {
  int s, e, w;
  Edge(int _s, int _e, int _w) : s(_s), e(_e), w(_w) {}
  bool operator<(Edge& b) { return this->w < b.w; }
};

class Solution {
 public:
  int swimInWater(vector<vector<int>>& grid) { /* dfs加2分 */
    int h = grid.size(), w = grid[1].size();
    vector<Edge> edges;
    for (int y = 0; y < h; y++) {
      for (int x = 0; x < w; x++) {
        if (x > 0) {
          edges.push_back(Edge(idx(y, x - 1, w), idx(y, x, w),
                               max(grid[y][x], grid[y][x - 1])));
        }
        if (y > 0) {
          edges.push_back(Edge(idx(y - 1, x, w), idx(y, x, w),
                               max(grid[y][x], grid[y - 1][x])));
        }
      }
    }
    sort(edges.begin(), edges.end());
    UnionFind uf(h * w + 1);
    int res;
    for (auto&& edge : edges) {
      uf.merge(edge.s, edge.e);
      if (uf.isconnect(idx(0, 0, w), idx(h - 1, w - 1, w))) {
        res = edge.w;
        break;
      }
    }
    return res;
  }
  int idx(int y, int x, int w) { return y * w + x; }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Mat<int> grid{{0, 1, 2, 3, 4},
                {24, 23, 22, 21, 5},
                {12, 13, 14, 15, 16},
                {11, 17, 18, 19, 20},
                {10, 9, 8, 7, 6}};
  Solution s;
  ic(s.swimInWater(grid));
  return 0;
}
