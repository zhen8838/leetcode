/*
 * @lc app=leetcode.cn id=845 lang=cpp
 *
 * [845] 数组中的最长山脉
 */

// @lc code=start
class Solution {
 public:
  int longestMountain(vector<int>& arr) {
    int ans = 0, cur = 0, i = 0, j, k, n = arr.size() - 1;
    // remove head;
    while (i < n and arr[i] >= arr[i + 1]) {
      i++;
    }

    while (i < n) {
      j = i;
      while (j < n and arr[j] < arr[j + 1]) {
        j++;
      }
      k = j;
      while (k < n and arr[k] > arr[k + 1]) {
        k++;
      }
      if (j - i > 0 and k - j > 0) {
        cur = k - i + 1;
      } else {
        cur = 0;
      }
      ans = max(ans, cur > 2 ? cur : 0);
      while (k < n and arr[k] == arr[k + 1]) {
        // remove same element
        k++;
      }
      i = k;
    }
    return ans;
  }
};
// @lc code=end
