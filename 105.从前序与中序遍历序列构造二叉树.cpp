/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildNode(preorder, inorder);
  }
  TreeNode* buildNode(vector<int> const& preorder, vector<int> const& inorder) {
    auto p = preorder.begin(), i = inorder.begin();
    auto j = i;
    if (preorder.empty()) {
      return nullptr;
    }

    while (*p != *j) {
      j++;
    }
    // 递归构造左子树和右子树
    vector<int> left_preorder = vector<int>(p + 1, p + (j - i) + 1);
    vector<int> left_inorder = vector<int>(i, j);

    vector<int> right_preorder = vector<int>(p + (j - i) + 1, preorder.end());
    vector<int> right_inorder = vector<int>(j + 1, inorder.end());

    TreeNode* left = buildNode(left_preorder, left_inorder);
    TreeNode* right = buildNode(right_preorder, right_inorder);

    TreeNode* root = new TreeNode(*p, left, right);

    return root;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  vector<int> preorder = {3, 9, 20, 15, 7};
  vector<int> inorder = {9, 3, 15, 20, 7};
  Solution s;
  s.buildTree(preorder, inorder);
  return 0;
}
