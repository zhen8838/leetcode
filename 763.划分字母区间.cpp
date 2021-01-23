/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  vector<int> partitionLabels(string S) {
    vector<int> umap(26, 0);
    vector<int> res;
    for (int i = 0; i < S.size(); i++) {
      umap[S[i] - 'a'] = i;
    }
    int start = 0, end = 0;
    for (int i = 0; i < S.size(); i++) {
      end = max(end, umap[S[i] - 'a']);
      if (i == end) {
        res.push_back(end - start + 1);
        start = end + 1;
      }
    }

    // ic(umap);
    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  string S = "ababcbacadefegdehijhklij";
  ic(s.partitionLabels(S));
  return 0;
}
