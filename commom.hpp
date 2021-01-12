#include <math.h>

#include <algorithm>
#include <bitset>
#include <climits>
#include <iostream>
#include <map>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include "icecream.hpp"
using namespace std;
#define ic IC

template <typename T>
using Mat = vector<vector<T>>;

template <typename T>
using Vec = vector<T>;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

ListNode* vector2list(vector<int>& nums) {
  ListNode *head = nullptr, *cur = nullptr;
  for (auto&& v : nums) {
    if (!head) {
      head = new ListNode(v);
      cur = head;
    } else {
      cur->next = new ListNode(v);
      cur = cur->next;
    }
  }
  return head;
}

TreeNode* vector2tree(vector<int>& nums) {
  queue<TreeNode*> nl;
  TreeNode* root = new TreeNode(nums.front());
  nums.erase(nums.begin());
  nl.push(root);
  while (nl.size()) {
    size_t n = nl.size();
    for (size_t i = 0; i < n; i++) {
      TreeNode* cur = nl.front();
      nl.pop();
      if (nums.empty()) {
        break;
      }
      int left = nums.front();
      nums.erase(nums.begin());
      if (left != 0) {
        cur->left = new TreeNode(left);
        nl.push(cur->left);
      }

      if (nums.empty()) {
        break;
      }
      int right = nums.front();
      nums.erase(nums.begin());
      if (right != 0) {
        cur->right = new TreeNode(right);
        nl.push(cur->right);
      }
    }
  }
  return root;
}

template <typename K, typename V>
void pmap(const map<K, V>& dict) {
  for (auto&& item : dict) {
    cout << item.first << ' ' << item.second << ',';
  }
  cout << endl;
}

template <typename V>
void pvec(const vector<V>& v) {
  for (auto&& item : v) {
    cout << item << ' ';
  }
  cout << endl;
}

template <typename T>
void pscalr(const T& t) {
  cout << t << endl;
}

template <typename T, typename... Args>
void pscalr(const T& t, Args... args) {
  cout << t << ", ";
  pscalr(args...);
}