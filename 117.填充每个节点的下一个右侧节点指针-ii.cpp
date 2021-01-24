/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */
#include "commom.hpp"
class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};
// @lc code=start
/*
// Definition for a Node.
*/

class Solution {
 public:
  Node* connect(Node* root) {
    if (not root) {
      return root;
    }

    if (root->left and root->right) {
      root->left->next = root->right;
    }
    Node* slid = root->right ? root->right : root->left;
    Node* node = root->next;
    if (slid) {
      while (node) {
        if (node->left) {
          slid->next = node->left;
          break;
        } else if (node->right) {
          slid->next = node->right;
          break;
        }
        node = node->next;
      }
    }
    // 右边先遍历
    connect(root->right);
    connect(root->left);
    return root;
  }
};
// @lc code=end
