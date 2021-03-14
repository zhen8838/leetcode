/*
 * @lc app=leetcode.cn id=706 lang=cpp
 *
 * [706] 设计哈希映射
 */

// @lc code=start
struct  Node {
  int k, v;
  Node* next;
  Node(int _k, int _v) : k(_k), v(_v), next(nullptr){};
};
class MyHashMap {
 private:
  Node* nodes[31251] = {nullptr};

 public:
  /** Initialize your data structure here. */
  MyHashMap() {}

  /** value will always be non-negative. */
  void put(int key, int value) {
    int id = key / 32, bid = key % 32;
    if (not nodes[id]) {
      nodes[id] = new Node(key, value);
      return;
    } else {
      Node *node = nodes[id], *last = node;
      while (node) {
        if (node->k == key) {
          node->v = value;
          return;
        }
        last = node;
        node = node->next;
      }
      last->next = new Node(key, value);
    }
  }

  /** Returns the value to which the specified key is mapped, or -1 if this map
   * contains no mapping for the key */
  int get(int key) {
    int id = key / 32, bid = key % 32;
    if (not nodes[id]) {
      return -1;
    } else {
      Node* node = nodes[id];
      while (node) {
        if (node->k == key) { return node->v; }
        node = node->next;
      }
    }
    return -1;
  }

  /** Removes the mapping of the specified value key if this map contains a
   * mapping for the key */
  void remove(int key) {
    int id = key / 32, bid = key % 32;
    if (not nodes[id]) {
      return;
    } else {
      Node *node = nodes[id], *last = node;
      while (node) {
        if (node->k == key) {
          if (node == last) {
            nodes[id] = node->next;
          } else {
            last->next = node->next;
          }
          delete node;
          return;
        }
        last = node;
        node = node->next;
      }
    }
  }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
// @lc code=end
