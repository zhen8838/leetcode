/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 */

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
  vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    vector<int> layer;
    queue<TreeNode*> q;
    int n;
    if (not root) {
      return res;
    }
    TreeNode* node;
    q.push(root);
    while (q.size()) {
      n = q.size();
      for (int i = 0; i < n; i++) {
        node = q.front(), q.pop();
        layer.push_back(node->val);
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
      res.push_back(layer);
      layer.clear();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};
// @lc code=end
