/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
class Solution {
 public:
  char nextGreatestLetter(vector<char>& letters, char target) {
    int l = 0, r = letters.size() - 1, mid;
    while (l < r) {
      mid = l + r >> 1;
      if (letters[mid] > target) r = mid;
      else l = mid + 1;
    }
    return letters[l] > target ? letters[l] : letters[(l + 1) % letters.size()];
  }
};
// @lc code=end
