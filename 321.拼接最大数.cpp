/*
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  /*
   * 这题是找最大子序列的升级版:
   * 1. 第一个序列找长度为n的最大子序列,第二个序列找长度为k-n的最大子序列
   * 2. 合并两个最大子序列,合并时注意需要保持相对顺序,
   * 3. 更新结果.
   */
  vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int len1 = nums1.size(), len2 = nums2.size();
    vector<int> ans;
    for (int n1 = 0; n1 <= k; n1++) {
      if (n1 > len1 or (k - n1) > len2) continue;
      vector<int> s1 = maxSubseq(nums1, n1), s2 = maxSubseq(nums2, k - n1);
      vector<int> tmp = merge(s1, s2);
      ans = ans.empty() ? tmp : cmp(ans, tmp);
    }
    return ans;
  }

  vector<int> maxSubseq(vector<int>& nums, int n) {
    int k = nums.size() - n;
    vector<int> s;
    for (int i = 0; i < nums.size(); i++) {
      while (s.size() and k and nums[i] > s.back()) { s.pop_back(), k--; }
      s.push_back(nums[i]);
    }
    while (k--) { s.pop_back(); }
    return s;
  }
  /* merge的时候需要注意保持最大的同时注意顺序
   * nums1 = [6, 7]     选这个6 因为7>0
   * nums2 = [6, 0, 4]
   */
  vector<int> merge(vector<int>& a, vector<int>& b) {
    int p1 = 0, p2 = 0, len1 = a.size(), len2 = b.size();
    vector<int> r;
    while (p1 < len1 and p2 < len2) {
      if (a[p1] == b[p2]) {
        int _p1 = p1 + 1, _p2 = p2 + 1;
        bool pushed = false;
        while (not pushed and _p1 < len1 and _p2 < len2) {
          if (a[_p1] > b[_p2]) r.push_back(a[p1++]), pushed = true;
          else if (a[_p1] < b[_p2])
            r.push_back(b[p2++]), pushed = true;
          else
            _p1++, _p2++;
        };
        if (not pushed)
          _p1 == len1 ? r.push_back(b[p2++]) : r.push_back(a[p1++]);
      } else if (a[p1] > b[p2]) {
        r.push_back(a[p1++]);
      } else {
        r.push_back(b[p2++]);
      }
    }
    while (p1 < len1) r.push_back(a[p1++]);
    while (p2 < len2) r.push_back(b[p2++]);
    return r;
  }

  /* 对比两个数组大小
  !
  必须要从-1开始++在前,因为如果++在后的话,最后一个元素如果不匹配,最终的结果都是等于len的.
   */
  vector<int> cmp(vector<int>& a, vector<int>& b) {
    int p1 = -1, p2 = -1, len = a.size();
    while (p1 < (len - 1) and a[++p1] == b[++p2]) {}
    return a[p1] > b[p2] ? a : b;
  }
};
// @lc code=end

int main() {
  vector<int> nums1{2, 8, 0, 4, 5, 1, 4, 8, 9, 9, 0, 8, 2, 9},
      nums2{5, 9, 6, 6, 4, 1, 0, 7};
  int k = 22;
  // vector<int> nums1{6, 7}, nums2{6, 0, 4};
  // int k = 5;
  Solution s;
  ic(s.maxNumber(nums1, nums2, k));
  vector<int> c{1, 2, 3};
  ic(s.cmp(c, c));
}