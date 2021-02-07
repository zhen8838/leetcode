/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
 public:
  int longestValidParentheses(string s) {
    int n = s.size(), ans = 0;
    /* 用栈模拟，加哨兵可以更加保持规律 */
    // stack<int> st;
    // st.push(-1);  //哨兵
    // for (int i = 0; i < n; i++) {
    //   if (s[i] == '(') {
    //     st.push(i);
    //   } else {
    //     st.pop();
    //     if (st.empty()) {
    //       st.push(i);
    //     } else {
    //       ans = max(ans, i - st.top());
    //     }
    //   }
    // }
    /* 用计数器就无法知道什么时候分段比如 "()((())"，所以从两边进行遍历得到最大结果
    
     */
    int left = 0, right = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        left++;
      } else {
        right++;
      }
      if (left == right) {
        cnt += (left + right);
        left = 0;
        right = 0;
        ans = max(ans, cnt);
      } else if (right > left) {
        right = 0;
        cnt = 0;
      }
    }
    left = 0, right = 0, cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == ')') {
        left++;
      } else {
        right++;
      }
      if (left == right) {
        cnt += (left + right);
        left = 0;
        right = 0;
        ans = max(ans, cnt);
      } else if (right > left) {
        right = 0;
        cnt = 0;
      }
    }

    return ans;
  }
};
// @lc code=end
