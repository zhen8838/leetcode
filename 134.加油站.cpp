/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int i, j, tmp;
    int n = gas.size();
    for (i = 0; i < n; i += j + 1) {
      tmp = 0;
      for (j = 0; j < n; j++) {
        int k = (i + j) % n;
        tmp = tmp + gas[k] - cost[k];
        if (tmp < 0) {
          break;
        }
      }
      if (j >= n) {
        return i;
      }
    }
    return -1;
  }
};
// @lc code=end
