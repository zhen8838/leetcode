/*
 * @lc app=leetcode.cn id=1203 lang=cpp
 *
 * [1203] 项目管理
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  /* 拓扑排序简单来说，是对于一张有向图 GG，我们需要将 GG 的 nn
   * 个点排列成一组序列，使得图中任意一对顶点 <u,v>，如果图中存在一条
   * u→v 的边，那么 u 在序列中需要出现在 v 的前面。 */
  vector<int> topSort(vector<int>& deg, vector<vector<int>>& graph,
                      vector<int>& items) {
    queue<int> Q;
    for (auto& item : items) {
      if (deg[item] == 0) {
        Q.push(item);
      }
    }
    vector<int> res;
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();
      res.emplace_back(u);
      for (auto& v : graph[u]) {
        if (--deg[v] == 0) {
          Q.push(v);
        }
      }
    }
    return res.size() == items.size() ? res : vector<int>{};
  }

  vector<int> sortItems(int n, int m, vector<int>& group,
                        vector<vector<int>>& beforeItems) {
    vector<vector<int>> groupItem(n + m);

    // 组间和组内依赖图
    vector<vector<int>> groupGraph(n + m);
    vector<vector<int>> itemGraph(n);

    // 组间和组内入度数组
    vector<int> groupDegree(n + m, 0);
    vector<int> itemDegree(n, 0);

    vector<int> id;
    for (int i = 0; i < n + m; ++i) {
      id.emplace_back(i);
    }

    int leftId = m;
    // 给未分配的 item 分配一个 groupId
    for (int i = 0; i < n; ++i) {
      if (group[i] == -1) {
        group[i] = leftId;
        leftId += 1;
      }
      groupItem[group[i]].emplace_back(i);
    }
    // 依赖关系建图
    for (int i = 0; i < n; ++i) {
      int curGroupId = group[i];
      for (auto& item : beforeItems[i]) {
        int beforeGroupId = group[item];
        if (beforeGroupId == curGroupId) {
          itemDegree[i] += 1;
          itemGraph[item].emplace_back(i);
        } else {
          groupDegree[curGroupId] += 1;
          groupGraph[beforeGroupId].emplace_back(curGroupId);
        }
      }
    }

    // 组间拓扑关系排序
    vector<int> groupTopSort = topSort(groupDegree, groupGraph, id);
    if (groupTopSort.size() == 0) {
      return vector<int>{};
    }
    vector<int> ans;
    // 组内拓扑关系排序
    for (auto& curGroupId : groupTopSort) {
      int size = groupItem[curGroupId].size();
      if (size == 0) {
        continue;
      }
      vector<int> res = topSort(itemDegree, itemGraph, groupItem[curGroupId]);
      if (res.size() == 0) {
        return vector<int>{};
      }
      for (auto& item : res) {
        ans.emplace_back(item);
      }
    }
    return ans;
  }
};
// @lc code=end
