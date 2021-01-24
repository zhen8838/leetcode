/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */
#include "commom.hpp"
// @lc code=start
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
  void flatten(TreeNode* root) {
    /* 找到root左边的右边前驱，将root右边给右边前驱 */
    if (not root) {
      return;
    }
    TreeNode* left = root->left;
    if (left) {
      TreeNode* pre = left;
      while (pre->right) {
        pre = pre->right;
      }
      pre->right = root->right;
      root->right = left;
      root->left = nullptr;
    }
    flatten(root->right);
  }
};
// @lc code=end
