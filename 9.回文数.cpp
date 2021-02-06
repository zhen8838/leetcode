/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
 public:
  bool isPalindrome(int x) {
    // if (x < 0) {
    //   return false;
    // }
    // vector<int> v;
    // while (x) {
    //   v.push_back(x % 10);
    //   x /= 10;
    // }
    // int l, r;
    // if (v.size() % 2 == 0) {
    //   l = (v.size() / 2) - 1, r = v.size() / 2;
    // } else {
    //   l = v.size() / 2;
    //   r = l;
    // }
    // return isp(v, l, r);
    if (x < 0 or ((x % 10) == 0 and x != 0)) {
      // 小于0 或者 以0结尾肯定不是(但0是)
      return false;
    }
    int rev = 0;
    while (x > rev) {
      // 这里翻转一半的数字就ok
      rev = rev * 10 + x % 10;
      x /= 10;
    }
    return rev == x or (rev / 10) == x;
  }
  bool isp(vector<int>& v, int l, int r) {
    while (0 <= l and r < v.size()) {
      if (v[l--] != v[r++]) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
