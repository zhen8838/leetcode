/*
 * @lc app=leetcode.cn id=992 lang=cpp
 *
 * [992] K 个不同整数的子数组
 */

// @lc code=start
class Solution {
 public:
  int subarraysWithKDistinct(vector<int>& A, int K) {
    return helper(A, K) - helper(A, K - 1);
  }
  int helper(vector<int>& A, int K) {
    int ans = 0;
    unordered_map<int, int> umap;
    for (int r = 0, l = 0; r < A.size(); r++) {
      umap[A[r]]++;
      while (umap.size() > K) {
        umap[A[l]]--;
        if (umap[A[l]] == 0) {
          umap.erase(A[l]);
        }
        l++;
      }
      
      /* 
      ! 求解最多K个不同数字组成的数组,通过累加的方式我们将[2,1]这种情况累积到结果中,最终我们只需要删除 [1],[2] 这些值就能获得恰好K个不同数字组成的数组个数.
      * 假设 1:
      * ans + 1 = ans + [1]
      * 假设 12:
      * ans + 2 = ans + [2] , [1,2]
      * 假设 121:
      * ans + 3 = ans + [1] , [2,1] , [1,2,1]
      */
      ans += r - l + 1;// 这里改成加上数组的长度
    }
    return ans;
  }
};
// @lc code=end
