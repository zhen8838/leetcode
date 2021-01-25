/*
 * @lc app=leetcode.cn id=959 lang=cpp
 *
 * [959] 由斜杠划分区域
 */
#include <numeric>
#include <unordered_set>

#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  vector<int> parent;
  int n_areas;

 public:
  int regionsBySlashes(vector<string>& grid) {
    int n = grid.size();
    parent.resize(n * n * 4);
    n_areas = n * n * 4;
    iota(parent.begin(), parent.end(), 0);
    auto idx = [&n](int y, int x, int id) {
      return y * (n * 4) + x * (4) + id;
    };

    for (size_t y = 0; y < n; y++) {
      for (size_t x = 0; x < n; x++) {
        // 当x和y大于0时，先让他们和相邻的方块进行连接。
        if (y > 0) {  // y大于0，可以和上面相连
          merge(idx(y - 1, x, 2), idx(y, x, 0));
        }
        if (x > 0) {  // x大于0，可以和左边相连
          merge(idx(y, x - 1, 1), idx(y, x, 3));
        }
        switch (grid[y][x]) {
          case ' ':  // 所有都和0相连
            // ic(idx(y, x, 0), idx(y, x, 1));
            merge(idx(y, x, 0), idx(y, x, 1));
            merge(idx(y, x, 0), idx(y, x, 2));
            merge(idx(y, x, 0), idx(y, x, 3));
            break;
          case '/':  // 3和0相连,2和1连
            merge(idx(y, x, 0), idx(y, x, 3));
            merge(idx(y, x, 1), idx(y, x, 2));
            break;
          case '\\':  // 1和0相连,2和3连
            merge(idx(y, x, 0), idx(y, x, 1));
            merge(idx(y, x, 3), idx(y, x, 2));
            break;
        }
      }
    }
    return n_areas;
  }

  int find(int x) {
    if (x != parent[x]) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void merge(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);
    if (rootx == rooty) {
      return;
    }
    parent[rooty] = rootx;
    n_areas--;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<string> grid{" /", "/ "};
  Solution s;
  ic(s.regionsBySlashes(grid));
  return 0;
}
