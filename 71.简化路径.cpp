/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  string simplifyPath(string path) {
    vector<string> s;
    string tmp;
    int i = 0, j = 0;
    while (i != path.size()) {
      // ic(s, tmp, path[i]);
      if (path[i] == '/') {
        if (not tmp.empty()) {
          if (tmp == ".") {
          } else if (tmp == "..") {
            if (not s.empty()) {
              s.pop_back();
            }
          } else {
            s.push_back(tmp);
          }
          tmp.clear();
        }
      } else {
        tmp.push_back(path[i]);
      }
      i++;
    }

    if (not tmp.empty()) {
      if (tmp == ".") {
      } else if (tmp == "..") {
        if (not s.empty()) {
          s.pop_back();
        }
      } else {
        s.push_back(tmp);
      }
      tmp.clear();
    }

    string res;
    for (auto&& c : s) {
      res.push_back('/');
      res.append(c);
    }
    if (res.empty()) {
      res.push_back('/');
    }

    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  string path = R"(/home/)";
  Solution s;
  ic(s.simplifyPath(path));
  return 0;
}
