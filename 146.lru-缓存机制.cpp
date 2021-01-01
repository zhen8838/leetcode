/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存机制
 */
#include <unordered_map>

#include "commom.hpp"
// using namespace std;
// @lc code=start
struct DLinkedList {
  int key;
  int value;
  DLinkedList* last;
  DLinkedList* next;
  DLinkedList() : key(0), value(0), last(nullptr), next(nullptr) {}
  DLinkedList(int _key, int _val)
      : key(_key), value(_val), last(nullptr), next(nullptr) {}
};

class LRUCache {
 private:
  int size;
  int capacity;
  DLinkedList* head;
  DLinkedList* tail;
  unordered_map<int, DLinkedList*> cache;

  void unlink(DLinkedList* node) {
    // 处理上下两个节点
    node->last->next = node->next;
    node->next->last = node->last;
    // 清理自身
    node->last = nullptr;
    node->next = nullptr;
  }

  void add2head(DLinkedList* node) {
    head->next->last = node;
    node->next = head->next;
    head->next = node;
    node->last = head;
  }

  void move2head(DLinkedList* node) {
    unlink(node);
    add2head(node);
  }

  DLinkedList* remove2tail(void) {
    DLinkedList* node = tail->last;
    unlink(node);
    return node;
  }

 public:
  LRUCache(int capacity)
      : size(0),
        capacity(capacity),
        head(new DLinkedList()),
        tail(new DLinkedList()) {
    head->next = tail;
    tail->last = head;
  }
  ~LRUCache() {
    auto node = head;
    for (auto&& item : cache) {
      delete item.second;
    }

    delete head;
    delete tail;
  }

  int get(int key) {
    if (!cache.count(key)) {
      return -1;
    }
    DLinkedList* node = cache[key];
    move2head(node);  // 将最近被使用的页面放到最前面
    return node->value;
  }

  void put(int key, int value) {
    if (cache.count(key)) {
      // 如果有值就更新数据,并且放到最前面
      DLinkedList* node = cache[key];
      node->value = value;
      move2head(node);
    } else {
      // 没有值就加节点,并且考虑是否需要删除数据
      if (size == capacity) {
        DLinkedList* unusenode = remove2tail();
        cache.erase(unusenode->key);
        delete unusenode;
        size--;
      }
      DLinkedList* node = new DLinkedList(key, value);
      cache[key] = node;
      add2head(node);
      size++;
    }
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main(int argc, char const* argv[]) {
  LRUCache cache(2);
  cache.put(2, 1);
  cache.put(1, 1);
  cache.put(2, 3);
  cache.put(4, 1);
  cache.get(1);
  cache.get(2);
  // cache.put(2, 1);
  // cache.put(3, 1);
  // LRUCache::~LRUCache();

  return 0;
}
