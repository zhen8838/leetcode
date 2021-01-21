/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

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
  ListNode* rotateRight(ListNode* head, int k) {
    if (not head) {
      return head;
    }

    ListNode *prehead = new ListNode(), *last = prehead, *node;
    prehead->next = head;
    node = prehead->next;
    int n = 0;
    while (node) {
      node = node->next;
      n++;
    }
    k %= n;
    if (k == 0) {
      return head;
    }
    k = n - k;
    node = prehead;
    while (node and k) {
      node = node->next;
      k--;
    }
    prehead->next = node->next;
    node->next = nullptr;
    node = prehead->next;
    while (node->next) {
      node = node->next;
    }
    node->next = head;
    return prehead->next;
  }
};
// @lc code=end
