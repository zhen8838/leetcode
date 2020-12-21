/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  vector<string> res;

 public:
  vector<string> generateParenthesis(int n) {
    string track;
    backtrack(track, 0, 0, n);
    return res;
  }
  void backtrack(string& track, int leftn, int rightn, int n) {
    if (leftn == n) {
      // 如果左括号数量等于n了，那么将所有右括号都加上就结束
      for (size_t j = 0; j < n - rightn; j++) {
        track.push_back(')');
      }
      res.push_back(track);
      // for (size_t j = 0; j < n - rightn; j++) {
      //   track.pop_back();
      // }
      return;
    }
    // 选择列表为[加左括号，加右括号]
    for (size_t i = 0; i < 2; i++) {
      // 做出选择，这里有个限制，就是左括号数量大于右括号数量的时候才可以加右括号(相当于剪枝)
      if (i == 0) {
        leftn++;
        track.push_back('(');
      } else {
        if (leftn > rightn) {
          rightn++;
          track.push_back(')');
        } else {
          return;
        }
      }
      IC(track, leftn, rightn);
      backtrack(track, leftn, rightn, n);  // 继续回溯
      // 取消选择
      if (leftn > rightn) {
        track.pop_back();
      }
    }
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<string> res = s.generateParenthesis(3);
  IC(res);
  return 0;
}
