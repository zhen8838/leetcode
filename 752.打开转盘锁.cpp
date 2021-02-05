/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */
#include <unordered_set>

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int openLock(vector<string>& deadends, string target) {
    unordered_set<string> uset(deadends.begin(), deadends.end());
    string s = "0000", t;
    if (uset.count(s)) {
      return -1;
    }
    uset.insert(s);
    queue<string> q;
    q.push(s);
    int step = 0;
    while (q.size()) {
      int n = q.size();
      for (int i = 0; i < n; i++) {
        s = q.front(), q.pop();
        if (s == target) return step;
        for (int j = 0; j < 4; j++) {
          for (auto k : {-1, 1}) {
            t = s;
            change(t, j, k);
            if (not uset.count(t)) {
              q.push(t);
              uset.insert(t);
            }
          }
        }
      }
      step++;
    }
    return -1;
  }

  void change(string& t, int j, int k) {
    t[j] += k;
    if (t[j] < '0') {
      t[j] = '9';
    }
    if (t[j] > '9') {
      t[j] = '0';
    }
  };
};
// @lc code=end
int main(int argc, char const* argv[]) {
  string target = "0009";
  vector<string> ends = {"8888", "0101", "0102", "1212", "2002"};
  Solution s;
  ic(s.openLock(ends, target));
  return 0;
}