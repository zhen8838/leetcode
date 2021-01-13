/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
  vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    TreeNode* node = root;
    vector<int> res;
    // q.push(node);
    while (node || s.size()) {
      while (node) {
        s.push(node);
        res.push_back(node->val);
        node = node->left;
      }
      node = s.top(), s.pop();
      node = node->right;
    }
    return res;
  }
};
// @lc code=end
