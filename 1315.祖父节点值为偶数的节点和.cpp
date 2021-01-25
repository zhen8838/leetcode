/*
 * @lc app=leetcode.cn id=1315 lang=cpp
 *
 * [1315] 祖父节点值为偶数的节点和
 */
#include "commom.hpp"
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  int sumEvenGrandparent(TreeNode* root) {
    if (not root) {
      return 0;
    }
    int ans = 0;
    if (root->val % 2 == 0) {
      if (root->left) {
        ans += root->left->left ? root->left->left->val : 0;
        ans += root->left->right ? root->left->right->val : 0;
      }
      if (root->right) {
        ans += root->right->left ? root->right->left->val : 0;
        ans += root->right->right ? root->right->right->val : 0;
      }
    }
    return ans + sumEvenGrandparent(root->left) +
           sumEvenGrandparent(root->right);
  }
};
// @lc code=end
