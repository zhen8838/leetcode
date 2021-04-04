/*
 * @lc app=leetcode.cn id=658 lang=cpp
 *
 * [658] 找到 K 个最接近的元素
 */
#include "commom.hpp"

// @lc code=start
class Solution {
 public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    // 先二分找到分界点然后再双指针,找右端点用模板2
    int l = 0, r = arr.size() - 1, mid;
    while (l < r) {
      mid = (l + r + 1) >> 1;
      if (arr[mid] <= x) l = mid;
      else
        r = mid - 1;
    }
    // 找到分界点之后要判断一下左边还是右边
    if ((l < arr.size() - 1) and (abs(arr[l] - x) > abs(arr[l + 1] - x))) {
      l = r = (l + 1);
    }
    k--;
    while (k--) {
      if (l == 0) {
        r++;
      } else if (r == arr.size() - 1) {
        l--;
      } else {
        int ldiff = abs(arr[l - 1] - x), rdiff = abs(arr[r + 1] - x);
        if (ldiff <= rdiff) {
          l--;
        } else if (ldiff > rdiff) {
          r++;
        }
      }
    }
    return vector<int>(arr.begin() + l, arr.begin() + r + 1);
  }
};
// @lc code=end

int main(int argc, char const* argv[]) { return 0; }
