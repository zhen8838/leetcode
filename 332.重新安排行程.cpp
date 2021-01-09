/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

#include <unordered_map>

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    int ids = 0;
    auto comp = [](string a, string b) {
      if (a[0] == b[0]) {
        if (a[1] == b[1]) {
          return a[2] < b[2];
        } else {
          return a[1] < b[1];
        }
      }
      return a[0] < b[0];
    };

    map<string, vector<string>> graph;
    for (auto&& ticket : tickets) {
      if (graph.find(ticket[0]) == graph.end()) {
        graph[ticket[0]] = vector<string>();
      }
      graph[ticket[0]].push_back(ticket[1]);
    }

    for (auto&& g : graph) {
      sort(g.second.begin(), g.second.end(), comp);
    }
    // ic(graph);
    vector<string> res;
    string start = "JFK";
    dfs(graph, res, start);
    return res;
  }

  void dfs(map<string, vector<string>>& graph, vector<string>& track,
           string& start) {
    while (!graph[start].empty()) {
      string next = graph[start][0];
      graph[start].erase(graph[start].begin());
      dfs(graph, track, next);
    }
    track.insert(track.begin(), start);
  }
};

// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<string>> tickets{{"JFK", "SFO"},
                                 {"JFK", "ATL"},
                                 {"SFO", "ATL"},
                                 {"ATL", "JFK"},
                                 {"ATL", "SFO"}};
  ic(s.findItinerary(tickets));
  return 0;
}
