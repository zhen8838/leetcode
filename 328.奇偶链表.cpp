/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
  ListNode* oddEvenList(ListNode* head) {
    ListNode *a = nullptr, *b = nullptr, *ca, *cb;
    if (head == nullptr) {
      return head;
    }
    a = head;
    b = head->next;
    ca = a;
    cb = b;
    while (cb != nullptr && cb->next != nullptr) {
      ca->next = cb->next;
      ca = ca->next;
      cb->next = ca->next;
      cb = cb->next;
    }

    ca->next = b;
    // cb->next = nullptr;
    return a;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums({1, 2, 3, 4, 5});
  auto head = vector2list(nums);
  Solution s;
  auto nhead = s.oddEvenList(head);
  while (nhead) {
    IC(nhead->val);
    nhead = nhead->next;
  }

  return 0;
}
