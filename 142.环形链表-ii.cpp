/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
  ListNode* detectCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast and fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) { break; }
    }
    if (not fast or not fast->next) { return nullptr; }
    fast = head;
    while (fast != slow) {
      fast = fast->next;
      slow = slow->next;
    }
    return fast;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Vec<int> nums{-21, 10,  17, 8, 4,  26, 5,  35, 33, -7,  -16, 27, -12, 6,
                29,  -12, 5,  9, 20, 14, 14, 2,  13, -24, 21,  23, -21, 5};
  auto head = vector2list(nums);
  Solution s;
  return 0;
}
