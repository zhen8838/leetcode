/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */
#include "commom.hpp"
// @lc code=start
class Solution {
 public:
  int characterReplacement(string s, int k) {
    // https://pic.leetcode-cn.com/578fc15b7b426eb61dcf1fd73bb87f1511d8733c474797dbb9188b706a219cc5.jpg
    vector<int> count(26, 0);
    int left = 0, right = 0, max_freq = 0;
    // 给定滑动窗口 0-0,开始滑动
    while (right < s.size()) {
      // right每经过一个字符串,count都+1
      count[s[right] - 'A']++;
      // 更新最大频率
      max_freq = max(max_freq, count[s[right] - 'A']);
      // 如果当前窗口内最大频率的子串加上k个还是小于窗口大小,那么收缩窗体
      if ((right + 1 - left) > (k + max_freq)) {
        count[s[left] - 'A']--;
        left++;
      }
      right++;
      // ic(count[0], count[1], left, right, max_freq);
    }
    return right - left;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  string str = "AABABBA";
  Solution s;
  s.characterReplacement(str, 1);
  return 0;
}
