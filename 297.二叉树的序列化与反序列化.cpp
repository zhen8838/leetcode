/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
class Codec {
 public:
  // Encodes a tree to a single string.
  // string serialize(TreeNode* root) {
  //   string res = "[";
  //   queue<TreeNode*> q;
  //   TreeNode* node;
  //   if (root == nullptr) {
  //     res += "]";
  //     return res;
  //   }

  //   q.push(root);

  //   while (!q.empty()) {
  //     int qsize = q.size();
  //     while (qsize--) {
  //       node = q.front(), q.pop();
  //       if (node == nullptr) {
  //         res += "null,";
  //       } else {
  //         res += (to_string(node->val) + ',');
  //         q.push(node->left);
  //         q.push(node->right);
  //       }
  //     }
  //   }
  //   res.pop_back();
  //   res += "]";
  //   return res;
  // }

  // void levelorder(TreeNode* root) {
  //   vector<vector<int>> res;
  //   level(root, 0, res);
  //   // ic(res);
  // }

  // void level(TreeNode* root, int n, vector<vector<int>>& res) {
  //   if (root == nullptr) {
  //     return;
  //   }
  //   if (res.size() == n) {
  //     res.push_back(vector<int>());
  //   }
  //   res[n].push_back(root->val);
  //   if (root->left) {
  //     level(root->left, n + 1, res);
  //   }
  //   if (root->right) {
  //     level(root->right, n + 1, res);
  //   }
  // }

  // int maxlevel(TreeNode* root, int level) {
  //   if (root == nullptr) {
  //     return level;
  //   }
  //   return max(maxlevel(root->left, level + 1),
  //              maxlevel(root->right, level + 1));
  // }

  // Decodes your encoded data to tree.
  // TreeNode* deserialize(string data) {
  //   data.erase(data.begin());
  //   data.pop_back();
  //   vector<string> nums;
  //   split(data, nums, ",");
  //   if (nums.empty()) {
  //     return nullptr;
  //   }

  //   queue<TreeNode*> nl;
  //   TreeNode* root = new TreeNode(stoi(nums.front()));
  //   nums.erase(nums.begin());
  //   nl.push(root);
  //   while (nl.size()) {
  //     size_t n = nl.size();
  //     for (size_t i = 0; i < n; i++) {
  //       TreeNode* cur = nl.front();
  //       nl.pop();
  //       if (nums.empty()) {
  //         break;
  //       }
  //       string left = nums.front();
  //       nums.erase(nums.begin());
  //       if (left != "null") {
  //         cur->left = new TreeNode(stoi(left));
  //         nl.push(cur->left);
  //       }

  //       if (nums.empty()) {
  //         break;
  //       }
  //       string right = nums.front();
  //       nums.erase(nums.begin());
  //       if (right != "null") {
  //         cur->right = new TreeNode(stoi(right));
  //         nl.push(cur->right);
  //       }
  //     }
  //   }
  //   return root;
  // }

  // static void split(const string& s, vector<string>& tokens,
  //                   const string& delimiters = " ") {
  //   string::size_type lastPos = s.find_first_not_of(delimiters, 0);
  //   string::size_type pos = s.find_first_of(delimiters, lastPos);
  //   while (string::npos != pos || string::npos != lastPos) {
  //     tokens.emplace_back(s.substr(lastPos, pos - lastPos));
  //     lastPos = s.find_first_not_of(delimiters, pos);
  //     pos = s.find_first_of(delimiters, lastPos);
  //   }
  // }
  string serialize(TreeNode* root) {
    if (!root) return "X";
    auto l = "(" + serialize(root->left) + ")";
    auto r = "(" + serialize(root->right) + ")";
    return l + to_string(root->val) + r;
  }

  inline TreeNode* parseSubtree(const string& data, int& ptr) {
    ++ptr;  // 跳过左括号
    auto subtree = parse(data, ptr);
    ++ptr;  // 跳过右括号
    return subtree;
  }

  inline int parseInt(const string& data, int& ptr) {
    int x = 0, sgn = 1;
    if (!isdigit(data[ptr])) {
      sgn = -1;
      ++ptr;
    }
    while (isdigit(data[ptr])) {
      x = x * 10 + data[ptr++] - '0';
    }
    return x * sgn;
  }

  TreeNode* parse(const string& data, int& ptr) {
    if (data[ptr] == 'X') {
      ++ptr;
      return nullptr;
    }
    auto cur = new TreeNode(0);
    cur->left = parseSubtree(data, ptr);
    cur->val = parseInt(data, ptr);
    cur->right = parseSubtree(data, ptr);
    return cur;
  }

  TreeNode* deserialize(string data) {
    int ptr = 0;
    return parse(data, ptr);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

int main(int argc, char const* argv[]) {
  // string data = "[1,2,3,null,null,4,5]";
  Codec c;
  string ss = c.serialize(root);
  TreeNode* root = c.deserialize(ss);
  // c.levelorder(root);
  ic(c.maxlevel(root, 0));
  ic(c.serialize(root));

  // ic(nums);
  return 0;
}
