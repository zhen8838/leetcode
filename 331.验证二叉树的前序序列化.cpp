/*
 * @lc app=leetcode.cn id=331 lang=cpp
 *
 * [331] 验证二叉树的前序序列化
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  bool isValidSerialization(string preorder) {
    if (preorder.size() == 1 and preorder[0] == '#') {
      return true;
    }  // null也是有效的
    vector<int> s;
    int n = preorder.size();
    int i = 0;
    while (i < n) {
      if (isdigit(preorder[i])) {
        while (i < n and isdigit(preorder[i])) { i++; }
        s.push_back(0);
      } else if (preorder[i] == '#') {
        if (s.empty()) { return false; }
        s.back() += 1;
        i++;
      } else if (preorder[i] == ',') {
        i++;
      }
      while (s.size() and s.back() == 2) {
        s.pop_back();
        if (s.size()) { s.back() += 1; }
      }
      if (s.empty() and i < n) { return false; }  //如果中途已经将root都pop了
    }
    return s.empty();
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  string str = "9,3,4,#,#,1,#,#,#,2,#,6,#,#";
  ic(s.isValidSerialization(str));
  return 0;
}
