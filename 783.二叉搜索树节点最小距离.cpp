/*
 * @lc app=leetcode.cn id=783 lang=cpp
 *
 * [783] 二叉搜索树节点最小距离
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
  TreeNode* last = nullptr;
  int mindiff = INT_MAX;

 public:
  int minDiffInBST(TreeNode* root) {
    if (not root) { return INT_MAX; }
    int leftdiff = minDiffInBST(root->left);
    int diff = INT_MAX;
    if (not last) {
      last = root;
    } else {
      diff = abs(last->val - root->val);
      last = root;
    }
    int rightdiff = minDiffInBST(root->right);
    return min({leftdiff, diff, rightdiff});
  }
};
// @lc code=end
