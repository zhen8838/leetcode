/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */
#include <unordered_map>

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> umap, imap;
    for (auto&& t : tasks) {
      umap[t]++;
      imap[t] = -n - 1;
    }

    int res = 0;
    while (umap.size()) {
      auto mp = umap.end();
      for (auto p = umap.begin(); p != umap.end(); p++) {
        if (res > imap[p->first] + n) {
          if (mp == umap.end()) {
            mp = p;
          } else if (p->second > mp->second) {
            mp = p;
          }
        }
      }
      if (mp != umap.end()) {
        // ic(mp->first);
        imap[mp->first] = res;
        mp->second--;
        if (mp->second == 0) {
          umap.erase(mp);
        }
      } else {
        // ic(' ');
      }

      res++;
    }
    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<char> nums{'A', 'A', 'A', 'A', 'A', 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
  int n = 2;
  Solution s;
  ic(s.leastInterval(nums, n));
  return 0;
}
