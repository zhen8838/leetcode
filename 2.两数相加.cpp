/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *head = nullptr, *end = nullptr;
    int val = 0, mod = 0;
    while (l1 != nullptr && l2 != nullptr) {
      val = l1->val + l2->val + mod;
      mod = val / 10;
      val = val - 10 * mod;
      if (head == nullptr) {
        head = new ListNode(val);
        end = head;
      } else {
        end->next = new ListNode(val);
        end = end->next;
      }
      l1 = l1->next;
      l2 = l2->next;
    }
    while (l1 != nullptr) {
      val = l1->val + mod;
      mod = val / 10;
      val = val - 10 * mod;
      end->next = new ListNode(val);
      end = end->next;
      l1 = l1->next;
    }
    while (l2 != nullptr) {
      val = l2->val + mod;
      mod = val / 10;
      val = val - 10 * mod;
      end->next = new ListNode(val);
      end = end->next;
      l2 = l2->next;
    }
    if (mod != 0) {
      end->next = new ListNode(mod);
    }

    return head;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  s.addTwoNumbers();
  return 0;
}
