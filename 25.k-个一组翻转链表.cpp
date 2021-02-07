/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *prehead = new ListNode(), *node = nullptr, *pre = nullptr, *cur;
    prehead->next = head;
    node = prehead->next;
    int n = 0;
    while (node) {
      node = node->next;
      n++;
    }
    pre = prehead;
    for (int i = 0; i < n / k; i++) {
      node = pre->next;
      for (int j = 0; j < k - 1; j++) {
        cur = node->next;
        node->next = cur->next;
        cur->next = pre->next;
        pre->next = cur;
      }
      pre = node;
    }
    return prehead->next;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> nums{1, 2, 3, 4, 5};
  auto l = vector2list(nums);
  Solution s;
  auto h = s.reverseKGroup(l, 5);
  while (h) {
    ic(h->val);
    h = h->next;
  }

  return 0;
}
