/*
 * @lc app=leetcode.cn id=1379 lang=cpp
 *
 * [1379] 找出克隆二叉树中的相同节点
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
  TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned,
                          TreeNode* target) {
    if (not original) {
      return nullptr;
    }

    if (cloned->val == target->val) {
      return cloned;
    }

    auto left = getTargetCopy(original->left, cloned->left, target);
    auto right = getTargetCopy(original->right, cloned->right, target);
    if (left) {
      return left;
    }
    return right;
  }
};
// @lc code=end
