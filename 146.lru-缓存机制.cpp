/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */

// @lc code=start
class LRUCache {
 private:
  struct ListNode {
    int k;
    int v;
    ListNode *next, *last;
    ListNode(int _k, int _v) : k(_k), v(_v){};
    ListNode() : v(0){};
  };
  ListNode *head, *tail;
  int size;
  unordered_map<int, ListNode*> umap;

 public:
  LRUCache(int capacity)
      : size(capacity), head(new ListNode()), tail(new ListNode()) {
    head->next = tail;
    head->last = tail;
    tail->last = head;
    tail->next = head;
  }

  int get(int key) {
    if (umap.count(key)) {
      movetohead(umap[key]);
      return umap[key]->v;
    }
    return -1;
  }

  void put(int key, int value) {
    if (umap.count(key)) {
      movetohead(umap[key]);
      umap[key]->v = value;
    } else {
      if (umap.size() == size) {
        umap.erase(tail->last->k);
        removenode(tail->last);
      }
      ListNode* node = new ListNode(key, value);
      umap[key] = node;
      inserttohead(node);
    }
  }
  void removenode(ListNode* node) {
    node->last->next = node->next;
    node->next->last = node->last;
    node->next = nullptr;
    node->last = nullptr;
  }

  void inserttohead(ListNode* node) {
    node->next = head->next;
    node->last = head;
    node->next->last = node;
    head->next = node;
  }
  void movetohead(ListNode* node) {
    removenode(node);
    inserttohead(node);
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
