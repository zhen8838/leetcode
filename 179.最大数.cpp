/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

#include "commom.hpp"

// @lc code=start
class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    vector<string> snum;
    for (auto&& i : nums) {
      snum.push_back(to_string(i));
    }
    // 问题在于拼接后序列的大小,那么比较的时候直接拼接之后比较即可!!!
    auto cmp = [](string& a, string& b) {
      auto na = a + b;
      auto nb = b + a;
      return na > nb;
    };
    sort(snum.begin(), snum.end(), cmp);

    string res;
    for (auto&& s : snum) {
      res.append(s);
    }
    if (res[0] == '0') {
      return "0";
    }

    return res;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{0, 1, 3};

  // Solution s;
  // ic(s.largestNumber(nums));
  ic("3" > "30");
  return 0;
}
