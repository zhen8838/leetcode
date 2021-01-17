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
    /* 重点在于一定要同时出发,并且slow会在没有走完一圈的情况下碰到fast,这个时候圆环剩下的长度正好就是进入节点的长度 */
    while (fast) {
      slow = slow->next;
      if (not fast->next) {
        return nullptr;
      }
      fast = fast->next->next;
      if (fast == slow) {
        auto node = head;
        while (node != slow) {
          node = node->next;
          slow = slow->next;
        }
        return node;
      }
    }
    return nullptr;
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
