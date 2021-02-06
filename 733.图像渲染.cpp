/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */

// @lc code=start
class Solution {
 private:
  int h, w;

 public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                int newColor) {
    queue<pair<int, int>> q;
    h = image.size();
    w = image[0].size();
    int x, y, nx, ny, n, oldColor;
    q.push({sc, sr});  // x,y
    oldColor = image[sr][sc];
    if (oldColor == newColor) {
      return image;
    }
    vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (q.size()) {
      n = q.size();
      for (int i = 0; i < n; i++) {
        tie(x, y) = q.front(), q.pop();
        for (auto&& [dx, dy] : dir) {
          nx = x + dx;
          ny = y + dy;
          if (isvalid(nx, ny) and image[ny][nx] == oldColor) {
            q.push({nx, ny});
          }
        }
        image[y][x] = newColor;
      }
    }
    return image;
  }

  bool isvalid(int x, int y) { return 0 <= x and x < w and 0 <= y and y < h; }
};
// @lc code=end
