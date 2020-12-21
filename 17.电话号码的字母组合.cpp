/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 private:
  vector<string> res;
  map<char, string> dict = {
      {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
      {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"},
  };

 public:
  vector<string> letterCombinations(string digits) {
    string track = "";
    if (digits.empty()) {
      return res;
    }
    backtrack(digits, track, 0, digits.size());
    return res;
  }

  void backtrack(string& digits, string& track, int first, int len) {
    // 结束选择
    if (first == len) {
      res.push_back(track);
      return;
    }

    char digit = digits[first];
    string chars = dict[digit];
    // 从选择列表中选择
    for (auto&& c : chars) {
      // 做一个选择
      track.push_back(c);
      backtrack(digits, track, first + 1, len);
      // 取消当前选择
      track.pop_back();
    }
  }

  // void backtrack(string& output, int first, int len) {
  //   // 结束选择
  //   if (first == len) {
  //     res.push_back(output);
  //     return;
  //   }

  //   // 从选择列表中选择
  //   for (size_t i = first; i < len; i++) {
  //     // 做一个选择
  //     IC(output[i], output[first]);
  //     swap(output[i], output[first]);
  //     backtrack(output, first + 1, len);
  //     // 取消当前选择
  //     swap(output[first], output[i]);
  //   }
  // }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<string> res = s.letterCombinations("234");
  IC(res);
  return 0;
}
