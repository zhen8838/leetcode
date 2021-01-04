/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode *head = nullptr, *tmphead = nullptr, *node = nullptr;
    if (l1 == nullptr) {
      return l2;
    }
    if (l2 == nullptr) {
      return l1;
    }

    while (l1 != nullptr and l2 != nullptr) {
      if (l1->val <= l2->val) {
        node = l1;
        l1 = l1->next;
      } else {
        node = l2;
        l2 = l2->next;
      }
      if (head == nullptr) {
        head = node;
        tmphead = head;
      } else {
        tmphead->next = node;
        tmphead = tmphead->next;
      }
    }
    tmphead->next = l1 ? l1 : l2;
    return head;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> a{1, 2, 4};
  vector<int> b{1, 3, 4};
  auto c = vector2list(a);
  auto d = vector2list(b);
  Solution s;
  auto head = s.mergeTwoLists(c, d);
  while (head) {
    ic(head->val);
    head = head->next;
  }

  return 0;
}
