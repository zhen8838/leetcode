/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */
#include "commom.hpp"
// @lc code=start
struct ListNode {
  int key, val;
  ListNode *last, *next;
  ListNode(int _k, int _v) : key(_k), val(_v), last(nullptr), next(nullptr){};
  ListNode() key(-1), val(-1), last(nullptr), next(nullptr) : {};
};

class LFUCache {
 private:
  map<int, *ListNode, greater<int>> used;
  unordered_map<int, *ListNode> umap;
  ListNode *head, *tail;
  int size, capacity;

 public:
  LFUCache(int capacity)
      : head(new ListNode()),
        tail(new ListNode()),
        size(0),
        capacity(capacity) {
    head->next = tail;
    head->last = tail;
    tail->last = head;
    tail->next = head;
    used[0] = tail;
  }

  int get(int key) {}

  void put(int key, int value) {
    if (umap.count(key)) {
      ListNode* node = new ListNode(key, value);
      if (used.begin()->first == 0) { used[1] = node; }
      addtohead(node);
    } else {
      if (size == capacity) {
      } else {
      }
    }
  }

  void addtohead(ListNode* node) {
    node->next = head->next;
    node->last = head;
    node->next->last = node;
    head->next = node;
  }
  
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
