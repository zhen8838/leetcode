/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 */

#include "commom.hpp"
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    auto node = head;
    vector<ListNode*> node_list;

    while (node != nullptr) {
      node_list.push_back(node);
      node = node->next;
    }
    int len = node_list.size(), pos;
    pos = len - n;
    if (pos == 0) {
      if (len > 1) {
        head = node_list[pos + 1];
      } else {
        head = nullptr;
      }
    } else if (pos == len) {
      ListNode* last_node = node_list[pos - 1];
      last_node->next = nullptr;
    } else {
      ListNode* last_node = node_list[pos - 1];
      last_node->next = last_node->next->next;
    }

    return head;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> arr = {1, 2, 3, 4, 5};
  ListNode* pnode = new ListNode(arr[arr.size() - 1]);
  for (int i = arr.size() - 2; i >= 0; i--) {
    pnode = new ListNode(arr[i], pnode);
  }

  auto S = Solution();
  auto head = S.removeNthFromEnd(pnode, 5);
  while (head != nullptr) {
    pscalr(head->val);
    head = head->next;
  }

  return 0;
}
