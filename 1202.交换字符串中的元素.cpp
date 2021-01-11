/*
 * @lc app=leetcode.cn id=1202 lang=cpp
 *
 * [1202] 交换字符串中的元素
 */
#include <unordered_map>

#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  vector<int> parents;

 public:
  string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    // 直接dfs不大行,利用dfs构建交换图,构建并查集,然后同一个集合中的字符升序排列,这里还是用路径压缩的方法做把
    for (size_t i = 0; i < s.size(); i++) {
      parents.push_back(i);
    }
    for (auto&& p : pairs) {
      dounion(p[0], p[1]);
    }
    // 将同一节点找出
    unordered_map<int, vector<int>> dict;
    for (int i = 0; i < s.size(); i++) {
      int rooti = dofind(i);
      if (dict.find(rooti) == dict.end()) {
        dict[rooti] = vector<int>{i};
      } else {
        dict[rooti].push_back(i);
      }
    }
    string tmp;
    for (auto&& [root, vmap] : dict) {
      if (vmap.size() >= 1) {
        // 大于1才需要sort
        for (auto&& idx : vmap) {
          tmp.push_back(s[idx]);
        }
        sort(tmp.begin(), tmp.end(), less<char>());
        for (size_t i = 0; i < vmap.size(); i++) {
          s[vmap[i]] = tmp[i];
        }
        tmp.clear();
      }
    }
    return s;
  }
  int dofind(int a) {
    if (a != parents[a]) {
      parents[a] = dofind(parents[a]);
    }
    return parents[a];
  }

  void dounion(int a, int b) {
    int roota = dofind(a);
    int rootb = dofind(b);
    parents[rootb] = roota;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  string S = "dcab";
  vector<vector<int>> paris = {{0, 3}, {1, 2}};
  ic(s.smallestStringWithSwaps(S, paris));
  return 0;
}
