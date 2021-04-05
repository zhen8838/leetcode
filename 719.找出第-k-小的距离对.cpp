/*
 * @lc app=leetcode.cn id=719 lang=cpp
 *
 * [719] 找出第 k 小的距离对
 */

// @lc code=start
class Solution {
 public:
  int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int l = 0, r = ((*nums.rbegin()) - (*nums.begin())), mid;
    while (l < r) {
      mid = l + r >> 1;
      if (has_K_pair(nums, mid, k)) r = mid;
      else l = mid + 1;
    }
    return l;
  }
  bool has_K_pair(vector<int>& nums, int mid, int k) {
    int cnt = 0, l = 0;
    // 用双指针的方式检测当前有多少个pair的差值大于mid
    for (int r = 0; r < nums.size(); r++) {
      while (nums[r] - nums[l] > mid) { l++; }
      cnt += (r - l);
      if (cnt >= k) { return true; }
    }
    return false;
  }
};
// @lc code=end
