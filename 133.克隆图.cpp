/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

class Node {
 public:
  int val;
  vector<Node*> neighbors;
  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }
  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }
  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};
// @lc code=start
/*
// Definition for a Node.
*/

class Solution {
 private:
  unordered_map<Node*, Node*> umap;

 public:
  Node* cloneGraph(Node* node) {
    if (node == nullptr) {
      return nullptr;
    }
    dfs(node);
    return umap[node];
  }
  void dfs(Node* node) {
    if (umap.count(node)) {
      return;
    }
    Node* cnode = new Node(node->val);
    umap[node] = cnode;
    for (auto&& n : node->neighbors) {
      dfs(n);
      if (umap.count(n)) {
        cnode->neighbors.push_back(umap[n]);
      }
    }
  }
};
// @lc code=end
