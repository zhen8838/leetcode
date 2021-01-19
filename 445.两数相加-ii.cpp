/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int len1 = 0, len2 = 0;
    auto p1 = l1, p2 = l2;
    while (p1) {
      p1 = p1->next;
      len1++;
    }
    while (p2) {
      p2 = p2->next;
      len2++;
    }
    // ListNode *prehead = new ListNode(), *node = prehead, *tmp;
    vector<int> l;
    p1 = l1, p2 = l2;
    if (len1 > len2) {
      for (size_t i = 0; i < len1 - len2; i++) {
        l.push_back(p1->val);
        p1 = p1->next;
      }
    } else if (len1 < len2) {
      for (size_t i = 0; i < len2 - len1; i++) {
        l.push_back(p2->val);
        p2 = p2->next;
      }
    }
    while (p1 and p2) {
      l.push_back(p1->val + p2->val);
      p1 = p1->next;
      p2 = p2->next;
    }
    int mod = 0;
    for (int i = l.size() - 1; i >= 0; i--) {
      l[i] += mod;
      mod = l[i] / 10;
      l[i] %= 10;
    }
    if (mod) {
      l.insert(l.begin(), mod);
    }
    if (l.empty()) {
      return nullptr;
    }

    ListNode *head, *node;
    head = new ListNode(l[0]);
    node = head;
    for (size_t i = 1; i < l.size(); i++) {
      node->next = new ListNode(l[i]);
      node = node->next;
    }
    return head;
  }
};
// @lc code=end
