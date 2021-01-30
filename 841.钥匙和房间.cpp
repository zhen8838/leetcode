/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    // 遍历的长，得用dfs！
    vector<int> visited(rooms.size(), 0);
    queue<int> q;
    int n, next;
    visited[0] = 1;
    for (auto&& room : rooms[0]) {
      q.push(room);
    }

    while (q.size()) {
      n = q.size();
      for (size_t i = 0; i < n; i++) {
        next = q.front(), q.pop();
        if (visited[next] == 0) {
          for (auto&& room : rooms[next]) {
            q.push(room);
          }
          visited[next] = 1;
        }
      }
    }
    for (auto&& v : visited) {
      if (v != 1) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
