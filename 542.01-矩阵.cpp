/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  int h, w;

 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    h = matrix.size();
    w = matrix[0].size();
    queue<pair<int, int>> q;
    pair<int, int> p;
    int nx, ny;
    for (int y = 0; y < h; y++) {
      for (int x = 0; x < w; x++) {
        if (matrix[y][x] != 0) {
          matrix[y][x] = INT_MAX;
        } else {
          q.push({x, y});
        }
      }
    }
    vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (q.size()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        p = q.front(), q.pop();
        for (auto&& [dx, dy] : dirs) {
          nx = p.first + dx, ny = p.second + dy;
          if (isvalid(nx, ny) and
              (matrix[ny][nx] > matrix[p.second][p.first] + 1)) {
            matrix[ny][nx] = matrix[p.second][p.first] + 1;
            q.push({nx, ny});
          }
        }
      }
    }
    return matrix;
  }
  bool isvalid(int x, int y) { return 0 <= x and x < w and 0 <= y and y < h; }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Mat<int> mat{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  Solution s;
  ic(s.updateMatrix(mat));
  return 0;
}
