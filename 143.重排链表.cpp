/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
  void reorderList(ListNode* head) {
    if (head) {
      ListNode* mid = forwardList(head);
      ListNode *tmphead, *tmpmid;
      tmpmid = mid->next;
      mid->next=nullptr; // avoid dead loop
      mid = reverseList(tmpmid);
      while (head && mid) {
        tmphead = head->next;
        tmpmid = mid->next;
        head->next = mid;
        mid->next = tmphead;
        head = tmphead;
        mid = tmpmid;
      }
    }
  }

  ListNode* reverseList(ListNode* head) {
    ListNode *left, *right, *tmp;
    if (head == nullptr) {
      return head;
    }
    left = head;
    right = head->next;
    while (right) {
      left->next = right->next;
      right->next = head;
      head = right;
      right = left->next;
    }
    return head;
  }
  ListNode* forwardList(ListNode* head) {
    ListNode *mid, *end;
    if (head == nullptr) {
      return head;
    }
    mid = head;
    end = head;
    while (end && end->next) {
      mid = mid->next;
      end = end->next->next;
    }
    return mid;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{1, 2, 3, 4};
  auto head = vector2list(nums);
  Solution s;
  s.reorderList(head);
  while (head) {
    ic(head->val);
    head = head->next;
  }

  return 0;
}
