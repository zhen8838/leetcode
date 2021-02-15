/*
 * @lc app=leetcode.cn id=765 lang=cpp
 *
 * [765] 情侣牵手
 */

// @lc code=start
class UnionFind {
 private:
  int group;
  vector<int> parent;

 public:
  UnionFind(int _n) : parent(_n), group(_n) {
    iota(parent.begin(), parent.end(), 0);
  }

  int find(int x) { return parent[x] == x ?: parent[x] : find(parent[x]); }

  void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) { return; }
    parent[y] = x;
    group--;
  }
};
class Solution {
 public:
  int minSwapsCouples(vector<int>& row) {}
};
// @lc code=end
