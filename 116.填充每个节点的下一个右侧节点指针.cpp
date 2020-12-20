/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
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
    dfs(root);
    return root;
  }

  void dfs(Node* root) {
    // 递归遍历比较好，其实就是visit root的时候将子节点的next节点进行设置即可。
    if (root == nullptr) {
      return;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return;
    }

    // 左边必指向右边
    root->left->next = root->right;
    // 如果我们已经有next了，那么可以跨root
    if (root->next) {
      root->right->next = root->next->left;
    }
    dfs(root->left);
    dfs(root->right);
  }

  Node* connect2(Node* root) {
    // 层序遍历可以，但是占用空间比较大，我们要用递归的方式，利用已有的next指针
    queue<Node*> l;
    Node* last = nullptr;
    if (root == nullptr) {
      return root;
    }

    l.push(root);
    while (l.size()) {
      size_t n = l.size();
      for (size_t i = 0; i < n; i++) {
        Node* cur = l.front();
        l.pop();
        if (last) {
          last->next = cur;
        }
        last = cur;
        if (cur->left) {
          l.push(cur->left);
        }
        if (cur->right) {
          l.push(cur->right);
        }
      }
      last = nullptr;
    }
    return root;
  }
};
// @lc code=end
