/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
  vector<int> inorderTraversal(TreeNode* root) {
    // vector<int> res;
    // vector<TreeNode*> tmp;
    // TreeNode* node = root;

    // while (node || tmp.size()) {
    //   while (node) {
    //     tmp.push_back(node);
    //     node = node->left;
    //   }

    //   node = tmp.front();
    //   tmp.pop_back();
    //   res.push_back(node->val);
    //   node = node->right;
    // }
    // return res;
    stack<TreeNode*> S;
    vector<int> v;
    TreeNode* rt = root;
    while (rt || S.size()) {
      while (rt) {
        S.push(rt);
        rt = rt->left;
      }
      rt = S.top();
      S.pop();
      v.push_back(rt->val);
      rt = rt->right;
    }
    return v;
  }
};
// @lc code=end
