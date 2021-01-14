/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode *prehead = new ListNode(), *l, *r;
    prehead->next = head;
    l = prehead;
    r = prehead->next;
    int flag = false;
    while (r and r->next) {
      while (r and r->next and r->val == r->next->val) {
        flag = true;
        r = r->next;
      }
      if (flag) {
        if (r) {
          r = r->next;
        }
        flag = false;
      }
      l->next = r;
      if (r and r->next and r->val != r->next->val) {
        // ic(r->val, r->next->val);
        l = r;
        r = r->next;
      }
    }
    l=prehead->next;
    delete prehead;
    return l;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Vec<int> v{1, 1};
  auto head = vector2list(v);
  Solution s;
  auto node = s.deleteDuplicates(head);
  while (node) {
    ic(node->val);
    node = node->next;
  }

  return 0;
}