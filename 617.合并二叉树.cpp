/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
 */

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
  TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    if (not root1 and not root2) {
      return nullptr;
    } else if (root1 and root2) {
      root1->val += root2->val;
    } else {
      root1 = root1 ? root1 : new TreeNode(root2->val);
    }
    // clang-format off
    auto left = mergeTrees(
      root1 ? root1->left : nullptr,
      root2 ? root2->left : nullptr);
    auto right = mergeTrees(
      root1 ? root1->right : nullptr, 
      root2 ? root2->right : nullptr);
    // clang-format on
    root1->left = left;
    root1->right = right;
    return root1;
  }
};
// @lc code=end
