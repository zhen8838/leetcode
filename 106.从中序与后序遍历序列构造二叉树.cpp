/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */
#include <unordered_map>

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
 private:
  unordered_map<int, int> imap;

 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    for (size_t i = 0; i < inorder.size(); i++) {
      imap[inorder[i]] = i;
    }
    return helper(inorder, 0, inorder.size(), postorder, 0, postorder.size());
  }

  TreeNode* helper(vector<int>& inorder, int is, int ie, vector<int>& postorder,
                   int ps, int pe) {
    if (is == ie) {
      return nullptr;
    }
    // ic(pe);
    TreeNode* root = new TreeNode(postorder[pe - 1]);
    if (ie - is == 1) {
      return root;
    }
    int div = imap[root->val];
    // ic(is, div, ps, ps + (div - ie));
    root->left = helper(inorder, is, div, postorder, ps, pe + (div - ie));
    root->right =
        helper(inorder, div + 1, ie, postorder, ps + (div - is), pe - 1);
    return root;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Vec<int> in{9, 3, 15, 20, 7}, po{9, 15, 7, 20, 3};
  Solution s;
  s.buildTree(in, po);
  return 0;
}
