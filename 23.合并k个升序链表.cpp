/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) {
      return nullptr;
    }
    auto cmp = [](ListNode* left, ListNode* right) {
      return (left->val) > (right->val);
    };
    // 优先队列
    priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
    for (int i = 0; i < lists.size(); i++) {
      if (lists[i]) {
        q.push(lists[i]);
      }
    }
    ListNode *prehead = new ListNode(), *tail = prehead, *node;
    while (q.size()) {
      node = q.top(), q.pop();
      tail->next = node;
      node = node->next;
      if (node) {
        q.push(node);
      }
      tail = tail->next;
    }
    tail = prehead->next;
    delete prehead;
    return tail;
  }
  ListNode* mergeKLists2(vector<ListNode*>& lists) {
    // 暴力合并
    if (lists.empty()) {
      return nullptr;
    }

    ListNode* head = lists[0];
    for (int i = 1; i < lists.size(); i++) {
      head = mergeLists(head, lists[i]);
    }
    return head;
  }
  ListNode* mergeLists(ListNode* l1, ListNode* l2) {
    ListNode *prehead = new ListNode(), *n1 = l1, *n2 = l2, *pre;
    pre = prehead;
    while (n1 and n2) {
      if (n1->val < n2->val) {
        pre->next = n1, n1 = n1->next;
      } else {
        pre->next = n2, n2 = n2->next;
      }
      pre = pre->next;
    }
    pre->next = n1 ? n1 : n2;
    pre = prehead->next;
    delete prehead;
    return pre;
  }
};
// @lc code=end
