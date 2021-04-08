/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */
#include <unordered_map>
using namespace std;
// @lc code=start
struct Node {
  int key, val;
  Node *last, *next;
  Node(int _k, int _v) : key(_k), val(_v), last(nullptr), next(nullptr){};
  Node() : key(-1), val(-1), last(nullptr), next(nullptr){};
};

struct List {
  Node *head, *tail;
  int size;
  List() : head(new Node()), tail(new Node()), size(0) {
    head->next = tail;
    tail->last = head;
  }

  void push_front(Node* node) {
    node->next = head->next;
    node->last = head;
    head->next->last = node;
    head->next = node;
    size++;
  }
  Node* unlink(Node* node) {
    node->next->last = node->last;
    node->last->next = node->next;
    node->last = nullptr;
    node->next = nullptr;
    size--;
    return node;
  }
  Node* pop_back() { return unlink(tail->last); }
};

class LRUCache {
 private:
  int size, capacity;
  unordered_map<int, Node*> keymap;
  List list;

 public:
  LRUCache(int capacity) : size(0), capacity(capacity) {}

  int get(int key) {
    if (not keymap.count(key)) { return -1; }
    Node* node = unlink(keymap[key]);
    add(node);
    return node->val;
  }

  void put(int key, int value) {
    Node* node = nullptr;
    if (keymap.count(key)) {
      node = unlink(keymap[key]);
      node->val = value;
      add(node);
    } else {
      if (size == capacity) {
        node = unlink(list.tail->last);
        delete node;
      }
      add(new Node(key, value));
    }
  }

  Node* unlink(Node* node) {
    keymap.erase(node->key);
    list.unlink(node);
    size--;
    return node;
  }
  void add(Node* node) {
    list.push_front(node);
    keymap[node->key] = node;
    size++;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
