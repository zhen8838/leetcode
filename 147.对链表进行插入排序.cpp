/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
  ListNode* insertionSortList(ListNode* head) {
    ListNode *prehead = new ListNode(INT_MIN), *cur = head, *node,
             *left = prehead;
    prehead->next = head;

    while (cur) {
      node = prehead;
      // ic(node->val, cur->val);
      while (node->next and node->next->val < cur->val) {
        node = node->next;
      }
      // ic(left,node->val);
      if (left == node) {
        left = left->next;
        cur = cur->next;
      } else {
        left->next = cur->next;
        cur->next = node->next;
        node->next = cur;
        cur = left->next;
      }
    }
    
    return prehead->next;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Vec<int> vec = {4, 2, 1, 3};
  auto head = vector2list(vec);
  Solution s;
  auto node = s.insertionSortList(head);
  while (node) {
    ic(node->val);
    node = node->next;
  }

  return 0;
}
