/*
 * @lc app=leetcode.cn id=395 lang=cpp
 *
 * [395] 至少有K个重复字符的最长子串
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  int res = 0;

 public:
  int longestSubstring(string s, int k) {
    if (s.empty() or s.size() < k) return 0;
    vector<int> umap(26, 0);
    for (auto&& c : s) { umap[c - 'a']++; }
    dfs(umap, s, 0, s.size() - 1, k);
    return res;
  }

  void dfs(vector<int> umap, string& s, int l, int r, int k) {
    if (r - l + 1 < res) { return; }
    while (l < r) {
      if (umap[s[l] - 'a'] < k) umap[s[l++] - 'a']--;
      if (umap[s[r] - 'a'] < k) umap[s[r--] - 'a']--;
      if (umap[s[l] - 'a'] >= k and umap[s[r] - 'a'] >= k) { break; }
    }
    int cnt = 0, sums = 0, less = INT_MAX, big = INT_MIN;
    for (auto&& i : umap) {
      if (i) {
        cnt++;
        sums += i;
        less = min(less, i);
        big = max(big, i);
      }
    }
    // ic(l, r, res);
    if ((sums < cnt * k) and (big < k)) return;
    if (less >= k) {
      res = max(res, r - l + 1);
      return;
    }
    umap[s[l] - 'a']--;
    dfs(umap, s, l + 1, r, k);
    umap[s[l] - 'a']++;

    umap[s[r] - 'a']--;
    dfs(umap, s, l, r - 1, k);
    umap[s[r] - 'a']++;
  }
};
// @lc code=end
int main(int argc, char const* argv[]) {
  string s = "ababacb";
  int k = 3;
  Solution S;
  S.longestSubstring(s, k);
  return 0;
}
