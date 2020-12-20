/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */
#include "commom.hpp"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    // 跑三次，第一次跑找到相差的个数，然后从多的那个开始跑掉多余部分，最后两个一起跑，找到相同值。
    ListNode *cur = nullptr, *a = headA, *b = headB;
    while (a and b) {
      if (a == b) {
        return a;
      }
      a = a->next;
      b = b->next;
    }
    if (a == nullptr) {
      a = headB;
    } else {
      b = headA;
    }
    while (a and b) {
      a = a->next;
      b = b->next;
    }
    if (a == nullptr) {
      a = headB;
    } else {
      b = headA;
    }
    while (a and b) {
      if (a == b) {
        return a;
      }
      a = a->next;
      b = b->next;
    }
    return nullptr;
  }
};
// @lc code=end
