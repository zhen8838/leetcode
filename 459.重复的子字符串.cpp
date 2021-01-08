/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */
#include <string>
#include <unordered_map>

#include "icecream.hpp"

using namespace std;

// @lc code=start
class Solution {
 public:
  bool repeatedSubstringPattern(string s) {
    int n = s.size();
    size_t start = 0, len;
    string last, cur;
    for (size_t i = 1; i < n; i++) {
      if (n % i == 0) {
        start = 0;
        len = i;
        last = s.substr(start, len);
        start += len;
        while (start < n) {
          cur = s.substr(start, len);
          // IC(start, last, cur);
          if (last != cur) {
            break;
          }
          start += len;
        }
        if (start == n) {
          return true;
        }
      }
    }
    return false;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  string str = "aba";
  IC(s.repeatedSubstringPattern(str));
  return 0;
}
