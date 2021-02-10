/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
 private:
  bool res = false;

 public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (not root) return false;
    return dfs(root, 0, targetSum);
  }
  bool dfs(TreeNode* root, int Sum, int targetSum) {
    Sum += root->val;
    if (not root->left and not root->right) {
      if (Sum == targetSum) {
        return true;
      }
      return false;
    }

    return ((root->left ? dfs(root->left, Sum, targetSum) : false) or
            (root->right ? dfs(root->right, Sum, targetSum) : false));
  }
};
// @lc code=end
