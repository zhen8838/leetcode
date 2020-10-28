/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */
#include "commom.hpp"
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start
class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    if (head == nullptr) {
      return head;
    }
    ListNode *left = nullptr, *right = nullptr;
    while (head->next) {
      right = head->next;
      head->next = left;
      left = head;
      head = right;
    }
    head->next = left;
    return head;
  }
};
// @lc code=end
