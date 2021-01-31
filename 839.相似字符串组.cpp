/*
 * @lc app=leetcode.cn id=839 lang=cpp
 *
 * [839] 相似字符串组
 */
#include <numeric>

#include "commom.hpp"
// @lc code=start
class UnionFind {
 private:
  vector<int> parent;

 public:
  int group;
  UnionFind(int _n) : parent(_n, 0), group(_n) {
    iota(parent.begin(), parent.end(), 0);
  }
  int find(int x) { return x == parent[x] ? parent[x] : find(parent[x]); }

  void merge(int x, int y) {
    if (x == y) {
      return;
    }
    parent[y] = x;
    group--;
  }
};

class Solution {
 public:
  int numSimilarGroups(vector<string>& strs) {
    UnionFind uf(strs.size());
    for (size_t i = 0; i < strs.size(); i++) {
      for (size_t j = i; j < strs.size(); j++) {
        int x = uf.find(i);
        int y = uf.find(j);
        if (x != y and isanagram(strs[i], strs[j])) {
          uf.merge(x, y);
        }
      }
    }
    return uf.group;
  }
  bool isanagram(string& a, string& b) {
    int e = 0;
    for (size_t i = 0; i < a.size(); i++) {
      if (a[i] != b[i]) {
        e++;
        if (e > 2) {
          return false;
        }
      }
    }
    return true;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<string> strs{"tars","rats","arts","star"};
  Solution s;
  ic(s.numSimilarGroups(strs));
  return 0;
}
