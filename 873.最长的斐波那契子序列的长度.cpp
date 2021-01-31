/*
 * @lc app=leetcode.cn id=873 lang=cpp
 *
 * [873] 最长的斐波那契子序列的长度
 */
#include <unordered_map>

#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int lenLongestFibSubseq(vector<int>& arr) {
    int n = arr.size(), x1;
    unordered_map<int, int> umap;
    for (size_t i = 0; i < arr.size(); i++) {
      umap[arr[i]] = i;
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    int ans = 0;

    for (int s = 0; s < n; s++) {
      for (int e = s + 1; e < n; e++) {
        x1 = arr[e] - arr[s];
        if (umap.count(x1) and umap[x1] < s) {
          dp[s][e] = dp[umap[x1]][s] + 1;
          ans = max(dp[s][e], ans);
        }
      }
    }
    return ans == 0 ? ans : ans + 2;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  Vec<int> nums = {1, 3, 7, 11, 12, 14, 18};
  s.lenLongestFibSubseq(nums);
  return 0;
}
