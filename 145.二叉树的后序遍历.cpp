/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
  vector<int> postorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    vector<int> res;
    TreeNode *node = root, *prev = nullptr;
    while (node or s.size()) {
      while (node) {
        s.push(node);
        node = node->left;
      }
      node = s.top(), s.pop();
      // 只有当前节点没有右子树,或者右子树刚刚被遍历过,否则push进去从右边继续遍历
      if (node->right == nullptr or node->right == prev) {
        res.push_back(node->val);
        prev = node;
        node = nullptr;
      } else {
        s.push(node);
        node = node->right;
      }
    }
    return res;
  }
};
// @lc code=end
