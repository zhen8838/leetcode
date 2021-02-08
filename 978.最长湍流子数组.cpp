/*
 * @lc app=leetcode.cn id=978 lang=cpp
 *
 * [978] 最长湍流子数组
 */

// @lc code=start
class Solution {
 public:
  int maxTurbulenceSize(vector<int>& arr) {
    // 插入一个哨兵简化流程
    arr.insert(arr.begin(), arr[0]);
    int cur = 1, diff, res = 0;
    bool pos = true;
    for (int i = 1; i < arr.size(); i++) {
      diff = arr[i] - arr[i - 1];
      if (diff > 0 or diff < 0) {
        if ((diff > 0) == pos) {  //相同状态
          cur = 2;
        } else {  // 不同状态
          cur++;
        }
        pos = (diff > 0);
      } else {  // 和上一个元素相等
        cur = 1;
      }
      res = max(res, cur);
    }
    return res;
  }
};
// @lc code=end
