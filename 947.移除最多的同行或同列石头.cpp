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
  unordered_map<int, pair<unordered_set<int>, unordered_set<int>>> > parent;

 public:
  int removeStones(vector<vector<int>>& stones) {
    auto x = unordered_set<int>(stones[0][0]);
    auto y = unordered_set<int>(stones[0][1]);
    parent[0] = make_pair(x, y);

    for (size_t i = 1; i < stones.size(); i++) {
      for (size_t j = 0; j < parent; j++) {
        /* code */
      }
    }
    for (size_t i = 0; i < stones.size(); i++) {
      // int xroot = dofind();
      // int yroot = dofind(yparent[i]);
      // dounion()
      parent[i] = min(xparent[i], yparent[i]);
    }

    // ic(xmap, ymap);
    ic(xparent, yparent, parent);
    // unordered_set<int> uset;
    // for (size_t i = 0; i < stones.size(); i++) {
    //   if (xparent[i] == yparent[i]) {
    //     uset.emplace(xparent[i]);
    //     // ic(xparent[i], stones[xparent[i]]);
    //   }
    // }

    // return stones.size() - uset.size();
    // for (size_t i = 0; i < stones; i++) {
    //   dounion(stones, stones[i][0], stones[i][1]);
    // }
    return 1;
  }
  int dofind(int x) {
    if (x != parent[x]) {
      parent[x] = dofind(parent[x]);
    }
    return parent[x];
  }
  void dounion(int x, int y) {
    int rootx = dofind(xparent[x]);
    int rooty = dofind(yparent[y]);
    parent[rooty] = rootx;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  // Mat<int> stones = {{0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
  Mat<int> stones = {{1, 0}, {0, 1}, {1, 1}};
  Solution s;
  ic(s.removeStones(stones));
  return 0;
}
