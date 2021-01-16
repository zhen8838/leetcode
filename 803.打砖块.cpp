/*
 * @lc app=leetcode.cn id=803 lang=cpp
 *
 * [803] 打砖块
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  vector<int> parent, count;

 public:
  vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
    /* 先把hits的地方消除 */
    auto gridbak = grid;
    for (auto&& hit : hits) {
      gridbak[hit[0]][hit[1]] = 0;
    }
    /* 将消除后的grid合并联通分量 */
    // 将2维映射到1维做联通 [h*w]
    int h = grid.size(), w = grid[0].size();
    for (int i = 0; i < h * w + 1; i++) {
      parent.push_back(i);
      count.push_back(1);
    }
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (gridbak[i][j] == 1) {
          if (i == 0) {
            // 第一行元素和top相连
            dounion(i * w + j, h * w);
          }
          if (i > 0 and gridbak[i - 1][j] == 1) {  // 和上一个节点相连
            dounion((i - 1) * w + j, i * w + j);
          }
          if (j > 0 and gridbak[i][j - 1] == 1) {  // 和左边节点相连
            dounion(i * w + (j - 1), i * w + j);
          }
        }
      }
    }
    // ic(gridbak, parent, count);
    // 翻转hit
    // reverse(hits.begin(), hits.end());
    vector<pair<int, int>> pairs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<int> ret(hits.size(), 0);
    for (int i = hits.size() - 1; i >= 0; i--) {
      int y = hits[i][0], x = hits[i][1];
      /* 考虑这次hit打的位置是不是无效位置 */
      if (grid[y][x] == 0) {
        continue;
      }
      // 获得添加当前节点前root的count数量
      int precount = getcount(h * w);

      if (y == 0) {
        dounion(h * w, x);
      }

      // 那么当前位置需要与上下左右进行连接
      for (auto&& [dy, dx] : pairs) {
        int ny = y + dy, nx = x + dx;
        if (ny >= 0 and ny < h and nx >= 0 and nx < w) {
          if (gridbak[ny][nx] == 1) {  // 将当前连接到有效的节点上去
            dounion(ny * w + nx, y * w + x);
            // ic(parent);
          }
        }
      }
      int curcount = getcount(h * w);
      // 如果没有恢复一个集合,那么是-1得到0, 否则掉下的集合数量是恢复的数量减去1
      ret[i] = max(0, curcount - precount - 1);
      gridbak[y][x] = 1;  // 将当前节点恢复
    }
    return ret;
  }

  int dofind(int x) {
    // int t = x;
    // while (t != parent[t]) {
    //   int tt = parent[t];
    //   parent[t] = parent[parent[t]];
    //   t = tt;
    // }
    if (x != parent[x]) {
      parent[x] = dofind(parent[x]);
    }
    return parent[x];
  }

  void dounion(int x, int y) {
    int rootx = dofind(x);
    int rooty = dofind(y);
    if (rootx == rooty) {
      return;
    }
    parent[rooty] = rootx;
    count[rootx] += count[rooty];
    // 添加计数,
  }
  int getcount(int x) { return count[dofind(x)]; }
};
// @lc code=end
int main(int argc, char const* argv[]) {
  Mat<int> a{{1, 1, 1}, {0, 1, 0}, {0, 0, 0}};
  Mat<int> b = {{0, 2}, {2, 0}, {0, 1}, {1, 2}};
  Solution s;
  ic(s.hitBricks(a, b));

  return 0;
}
