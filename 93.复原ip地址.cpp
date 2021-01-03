/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  vector<string> res;

 public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> track;
    dfs(s, track, 0, s.size());
    return res;
  }

  void dfs(string& s, vector<string>& track, int pos, int len) {
    if (len == 0) {
      if (track.size() == 4) {
        res.push_back(track[0] + '.' + track[1] + '.' + track[2] + '.' +
                      track[3]);
      }
      return;
    }
    for (size_t i = 1; i <= 3; i++) {
      // ic((pos + i));
      if ((pos + i) > s.size()) {
        continue;
      }
      if ((len - i) > (3 * (3 - track.size()))) {
        continue;
      }

      string subs = s.substr(pos, i);
      if (subs.size() > 1 and subs[0] == '0') {
        // 剪枝以0开头大于1位的ip,
        continue;
      }
      // ic(subs.size(),)
      if (subs.size() == 3 and (stoi(subs) > 255)) {
        // 3位的ip不能大于255
        continue;
      }

      // ic(subs);
      track.push_back(subs);
      dfs(s, track, pos + i, len - i);
      track.pop_back();
    }
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  string str = "19216811";
  Solution s;
  auto res = s.restoreIpAddresses(str);
  ic(res);

  return 0;
}
