/*
 * @lc app=leetcode.cn id=847 lang=cpp
 *
 * [847] 访问所有节点的最短路径
 */
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size(), target = 0;
    queue<pair<int, int>> q;
    unordered_map<string, bool> isVisited;
    for (int i = 0; i < n; i++) {
      int path = 1 << i;
      target |= path;
      q.push(make_pair(path, i));
      isVisited[to_string(path) + "-" + to_string(i)] = true;
    }
    int ans = 0;
    while (!q.empty()) {
      for (int i = q.size() - 1; i >= 0; i--) {
        pair<int, int> top = q.front();
        q.pop();
        if (top.first == target) return ans;
        for (int next : graph[top.second]) {
          int path = top.first | (1 << next);
          string str = to_string(path) + "-" + to_string(next);
          if (isVisited[str]) continue;
          isVisited[str] = true;
          q.push(make_pair(path, next));
        }
      }
      ans++;
    }
    return -1;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<vector<vector<int>>> inputs = {{1, 2, 3}, {0}, {0}, {0}};
  return 0;
}
