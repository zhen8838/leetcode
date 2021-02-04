/*
 * @lc app=leetcode.cn id=402 lang=cpp
 *
 * [402] 移掉K位数字
 */
// @lc code=start
class Solution {
 public:
  string removeKdigits(string num, int k) {
    string res;
    for (auto&& s : num) {
      // 这里是模板！
      while (res.size() and k > 0 and s < res.back()) {
        res.pop_back();
        k--;
      }
      res.push_back(s);
    }
    while (res.size() and k) {
      res.pop_back();
      k--;
    }

    if (res.size() > 1 and res[0] == '0') {
      int i = 0;
      while (res[i] == '0') {
        i++;
      }
      res = res.substr(i, res.size());
    }
    if (res.empty()) {
      res.push_back('0');
    }

    return res;
  }
};
// @lc code=end
