/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
 */
#include <unordered_map>

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    unordered_map<int, int> umap;
    for (size_t i = 1; i < points.size(); i++) {
      umap.emplace(i, INT_MAX);  // index,distance
    }
    // 每次找和当前点最近的点就完事了!
    int cur = 0, cost = 0;
    while (not umap.empty()) {
      int minidx = min_distance(points, umap, cur);
      cost += umap[minidx];
      cur = minidx;
      umap.erase(minidx);
    }

    // p.push_back(0);
    // w.push_back(INT_MIN);
    // for (size_t i = 1; i < points.size(); i++) {
    //   p.push_back(i - 1);
    //   w.push_back(val(points, i - 1, i));
    // }
    // for (size_t i = 1; i < points.size(); i++) {
    //   auto a = points[i - 1], b = points[i];

    // }
    return cost;
  }
  int min_distance(vector<vector<int>>& points, unordered_map<int, int>& umap,
                   int cur) {
    int mindis = INT_MAX;
    int minidx;
    for (auto p = umap.begin(); p != umap.end(); p++) {
      int distance = val(points, p->first, cur);
      // 先更新当前点的距离
      if (distance < p->second) {
        p->second = distance;
      }
      if (p->second < mindis) {
        mindis = p->second;
        minidx = p->first;
      }
    }
    return minidx;
  }
  int val(vector<vector<int>>& points, int x, int y) {
    return abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1]);
  }
};
// @lc code=end
