/*
 * @lc app=leetcode.cn id=721 lang=cpp
 *
 * [721] 账户合并
 */
#include <unordered_map>
#include <unordered_set>

#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  vector<int> p;

 public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    /* 这™都能100 beats woc */
    vector<vector<string>> ans;
    unordered_map<string, int> mails;
    int n = accounts.size();
    int cnt = 0;
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 1; j < accounts[i].size(); j++) {
        if (mails.find(accounts[i][j]) == mails.end()) {
          mails.emplace(accounts[i][j], cnt++);
        }
      }
    }
    for (size_t i = 0; i < n + mails.size(); i++) {
      p.push_back(i);
    }
    // ic(p);
    for (size_t i = 0; i < n; i++) {
      // string name = accounts[i][0];
      int rootx = dofind(i);
      for (size_t j = 1; j < accounts[i].size(); j++) {
        int rooty = dofind(n + mails[accounts[i][j]]);
        p[rooty] = rootx;
        // ic(p);
      }
    }
    for (size_t i = 0; i < n; i++) {
      int pi = dofind(i);
      if (pi == i) {
        vector<string> res;
        for (auto&& [mail, j] : mails) {
          if (pi == dofind(n + j)) {
            res.push_back(mail);
          }
        }
        sort(res.begin(), res.end());
        res.insert(res.begin(), accounts[pi][0]);
        ans.push_back(res);
      }
    }
    // ic(p);
    // ic(mails);

    return ans;
  }

  int dofind(int x) {
    if (x != p[x]) {
      p[x] = dofind(p[x]);
    }
    return p[x];
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<vector<string>> accounts{
      {"John", "johnsmith@mail.com", "john00@mail.com"},
      {"John", "johnnybravo@mail.com"},
      {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
      {"Mary", "mary@mail.com"}};
  ic(s.accountsMerge(accounts));

  return 0;
}
