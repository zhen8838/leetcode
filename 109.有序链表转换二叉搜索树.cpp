/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  TreeNode* sortedListToBST(ListNode* head) { return dfs(head, nullptr); }
  TreeNode* dfs(ListNode* head, ListNode* end) {
    if (head == end) {
      return nullptr;
    }
    ListNode *slow = head, *fast = head;
    // 把判断加到这里就好了
    while (fast != end and fast->next != end) {
      slow = slow->next;
      fast = fast->next->next;
    }
    TreeNode* root = new TreeNode(slow->val);
    root->left = dfs(head, slow);
    root->right = dfs(slow->next, end);
    return root;
  }
};
// @lc code=end
