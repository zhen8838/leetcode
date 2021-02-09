/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
  bool res = true;

 public:
  bool isBalanced(TreeNode* root) {
    if (not root) {
      return res;
    }
    calcheight(root);
    return res;
  }
  int calcheight(TreeNode* root) {
    if (not root) {
      return 0;
    }
    int left = calcheight(root->left);
    int right = calcheight(root->right);
    if (abs(left - right) > 1) {
      res = false;
    }
    return max(left, right) + 1;
  }
};
// @lc code=end
