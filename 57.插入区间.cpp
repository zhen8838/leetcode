/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    vector<vector<int>> res;
    int l = newInterval[0], r = newInterval[1];
    bool flag = true;
    for (auto&& rg : intervals) {
      int s = rg[0], e = rg[1];
      if (r < s) {  // 在左边插入
        if (flag) {
          res.push_back({l, r});
          flag = false;
        }
        res.push_back(rg);
      } else if (l > e) {  // 在右边插入
        res.push_back(rg);
      } else {
        // 有交集 可能是r在其中或者l在其中,那就扩展交集
        // NOTE 重点还是扩展交集的代码
        l = min(l, s);
        r = max(r, e);
      }
    }
    if (flag) {
      // 如果还没有被放入,就放入
      res.push_back({l, r});
    }

    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Mat<int> mat{{1, 5}};
  Vec<int> nums{1, 7};
  Solution s;
  ic(s.insert(mat, nums));
  return 0;
}
