/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
  int res = INT_MIN;

 public:
  int maxPathSum(TreeNode* root) {
    dfs(root);
    return res;
  }
  int dfs(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    int left = max(dfs(root->left), 0);
    int right = max(dfs(root->right), 0);
    int val = root->val + left + right;
    res = max(res, val);
    // 返回的时候我们考虑到如果一个路径要经过父节点，那么肯定走最大的一条路线。
    return root->val + max(left, right);
  }
};
// @lc code=end
