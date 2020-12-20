/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int left = 0, right = 0, n = s.length(), mlen = 0;
    if (s.size() <= 1) {
      return s.size();
    }
    // 把dict改成桶排序，也就是直接开大小256的数组,速度起飞
    // map<char, int> dict;
    int dict[130] = {0};
    while (right < n) {
      if (dict[s[right]] == 0) {
        dict[s[right++]]++;
        mlen = (right - left) > mlen ? (right - left) : mlen;
      } else {
        dict[s[left]]--;
        left++;
      }
    }
    return mlen;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  IC(s.lengthOfLongestSubstring("abcabcbb"));
  return 0;
}
