/*
 * @lc app=leetcode.cn id=947 lang=cpp
 *
 * [947] 移除最多的同行或同列石头
 */
#include <unordered_map>
#include <unordered_set>

#include "commom.hpp"
// @lc code=start

class Solution {
 private:
  vector<int> xparent, yparent, parent;

 public:
  int removeStones(vector<vector<int>>& stones) {
    unordered_map<int, int> xmap, ymap;
    int xmax = 0, ymax = 0;
    for (size_t i = 0; i < stones.size(); i++) {
      if (xmap.find(stones[i][0]) == xmap.end()) {
        xmap[stones[i][0]] = xmax++;
        // xmax = i + 1;
      }
      if (ymap.find(stones[i][1]) == ymap.end()) {
        ymap[stones[i][1]] = ymax++;
        // ymax = i + 1;
      }
      xparent.push_back(xmap[stones[i][0]]);
      yparent.push_back(ymap[stones[i][1]]);
    }
    for (size_t i = 0; i < xmax + ymax; i++) {
      parent.push_back(i);
    }
    // ic(xparent, yparent);
    // ic(parent);
    for (size_t i = 0; i < stones.size(); i++) {
      dounion(xparent[i], yparent[i] + xmax);
    }
    unordered_set<int> uset;
    // uset.merge();
    for (auto&& x : xparent) {
      uset.emplace(dofind(x));
    }
    return stones.size() - uset.size();
  }
  //  private:
  //   vector<int> parent;

  //  public:
  //   int removeStones(vector<vector<int>>& stones) {
  //     constexpr int offset = 10000 + 1;
  //     for (size_t i = 0; i < offset * 2; i++) {
  //       parent.push_back(i);
  //     }
  //     for (auto&& stone : stones) {
  //       dounion(stone[0], offset + stone[1]);
  //     }
  //     unordered_set<int> uset;
  //     for (auto&& stone : stones) {
  //       uset.insert(dofind(stone[0]));
  //     }
  //     return stones.size() - uset.size();
  //   }
  int dofind(int num) {
    if (num != parent[num]) {
      parent[num] = dofind(parent[num]);
    }
    return parent[num];
  }
  void dounion(int x, int y) {
    // ic(x, y);
    int rootx = dofind(x);
    int rooty = dofind(y);
    parent[rooty] = rootx;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Mat<int> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
  // Mat<int> stones = {{1, 0}, {0, 1}, {1, 1}};
  Solution s;
  ic(s.removeStones(stones));
  return 0;
}
