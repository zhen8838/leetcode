/*
 * @lc app=leetcode.cn id=1191 lang=cpp
 *
 * [1191] K 次串联后最大子数组之和
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int kConcatenationMaxSum(vector<int>& arr, int k) {
    // fuck!!! -5,-2,0,0,3,9,-2,-5,4,-5,-2,0,0,3,9,-2,-5,4 ,why answer is 20?
    // if (arr.empty()) {
    //   return 0;
    // }

    // long minsub = arr[0], maxsub = arr[0], maxval = arr[0], minval = arr[0],
    //      total = arr[0], maxele = arr[0], ans;
    // long mask = 1e9 + 7;
    // for (size_t i = 1; i < arr.size(); i++) {
    //   minsub = min((long)arr[i], minsub + arr[i]);
    //   maxsub = max((long)arr[i], maxsub + arr[i]);
    //   maxval = max(maxsub, maxval);
    //   minval = min(minsub, minval);
    //   total += arr[i];
    //   maxele = max(maxele, (long)arr[i]);
    // }
    // // 如果全是负的元素,那么返回0.
    // if (minval == total) {
    //   return 0;
    // }
    // if (k == 1) {
    //   ans = maxval;
    // } else if (k == 2) {
    //   ans = max(maxval, total - minval);
    // } else {
    //   ans = max(maxval, total - minval);
    //   ans = ans == total ? ans + ans : ans;
    //   if (total > 0) {
    //     // 如果 k > 2，并且 total >0，那么相当于 arr * 2
    //     // 的情形中间加塞了k-2段arr
    //     ans = (k - 2) * total + ans;
    //   } else {
    //     // 如果 k > 2，并且 sum(arr)<=0，那么就是求 arr * 2 的最大子数组的和
    //     ans = ans;
    //   }
    // }

    // return ans % mask;
    int64_t ans = 0, len = arr.size(), mask = 1e9 + 7;
    int maxsub = 0;
    for (size_t i = 0; i < min(k, 2) * len; i++) {
      maxsub = max(arr[i % len] + maxsub, arr[i % len]);
      if (maxsub > ans) {
        ans = maxsub;
      }
      // ic(maxsub);
    }
    if (k > 2) {
      int64_t total = 0;
      for (auto&& i : arr) {
        total += i;
      }
      // ic(total);
      if (total > 0) {
        ans = total * (k - 2) + ans;
      } else {
        ans = ans;
      }
      // ic(ans);
    }
    return ans % mask;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> arr{-5, -2, 0, 0, 3, 9, -2, -5, 4};
  s.kConcatenationMaxSum(arr, 5);
  return 0;
}
