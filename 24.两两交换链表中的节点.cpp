/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
  ListNode* swapPairs(ListNode* head) {
    ListNode *prehead = new ListNode(), *node = nullptr, *last = nullptr;
    prehead->next = head;
    last = prehead;
    node = last->next;
    while (node and node->next) {
      last->next = node->next;
      node->next = last->next->next;
      last->next->next = node;
      last = node;
      node = node->next;
    }
    last = prehead->next;
    delete prehead;
    return last;
  }
};
// @lc code=end
