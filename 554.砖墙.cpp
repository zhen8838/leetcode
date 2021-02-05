/*
 * @lc app=leetcode.cn id=554 lang=cpp
 *
 * [554] 砖墙
 */

// @lc code=start
class Solution {
 public:
  int leastBricks(vector<vector<int>>& wall) {
    int res = 0;
    unordered_map<int, int> umap;
    for (size_t i = 0; i < wall.size(); i++) {
      for (size_t j = 0; j < wall[i].size() - 1; j++) {
        if (j > 0) {
          wall[i][j] += wall[i][j - 1];
        }
        umap[wall[i][j]]++;
      }
    }

    for (auto&& item : umap) {
      res = max(res, item.second);
    }
    return wall.size() - res;
  }
};
// @lc code=end
