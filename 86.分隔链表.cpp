/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */
#include "commom.hpp"
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    ListNode *preleft = new ListNode(), *preright = new ListNode(),
             *left = preleft, *right = preright, *node = head;
    while (node) {
      if (node->val < x) {
        left->next = node;
        node = node->next;
        left = left->next;
      } else {
        right->next = node;
        node = node->next;
        right = right->next;
      }
    }
    left->next = preright->next;
    left = preleft->next;
    right->next = nullptr;
    delete preleft;
    delete preright;
    return left;
  }
};
// @lc code=end
