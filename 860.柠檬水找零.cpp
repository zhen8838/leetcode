/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
 public:
  bool lemonadeChange(vector<int>& bills) {
    map<int, int, greater<int>> umap{{20, 0}, {10, 0}, {5, 0}};
    int pay;
    bool payed;
    for (auto&& bill : bills) {
      pay = bill - 5;
      while (pay) {
        payed = false;
        for (auto&& item : umap) {
          if (item.second > 0 and item.first <= pay) {
            item.second--;
            payed = true;
            pay -= item.first;
            continue;
          }
        }
        if (payed == false) {
          return false;
        }
      }
      umap[bill]++;
    }
    return true;
  }
};
// @lc code=end
