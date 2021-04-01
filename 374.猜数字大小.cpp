/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
 public:
  int guessNumber(int n) {
    long long l = 0, r = n, mid;
    while (l <= r) {
      mid = (l + r) >> 1;
      if (guess(mid) == 0) {
        return mid;
      } else if (guess(mid) == -1) {
        r = mid;
      } else if (guess(mid) == 1) {
        l = mid + 1;
      }
    }
    return mid;
  }
};
// @lc code=end
