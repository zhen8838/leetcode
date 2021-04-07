/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */
#include <iostream>
#include <list>
#include <unordered_map>

#include "commom.hpp"

// @lc code=start

struct Node {
  int key, val, freq;
  Node(int _k, int _v) : key(_k), val(_v), freq(1){};
  Node(int _k, int _v, int _f) : key(_k), val(_v), freq(_f){};
};

class LFUCache {
 private:
  unordered_map<int, list<Node>::iterator> keymap;
  unordered_map<int, list<Node>> freqmap;
  int size, capacity, minfreq;

 public:
  LFUCache(int capacity) : size(0), capacity(capacity), minfreq(0) {}

  int get(int key) {
    if (not keymap.count(key)) { return -1; }
    // 取出对应的node指针和freqlist
    auto node = earse(key);
    // 放到上级freqlist的头部
    add(node);
    return node.val;
  }

  void print() {
    for (auto&& [f, l] : freqmap) {
      cout << "f " << f << " : ";
      for (auto&& n : l) { cout << n.key << "-" << n.val << " "; }
      cout << endl;
    }
  }

  void put(int key, int value) {
    if (capacity == 0) { return; }
    if (keymap.count(key)) {
      get(key);
      keymap[key]->val = value;
    } else {
      if (size == capacity) { earse(freqmap[minfreq].rbegin()->key); }
      minfreq = 1;
      add(Node(key, value, 1));
    }
  }

  /**
   * @brief 将node插入到对应的freqlist上
   *
   * @param node
   */
  void add(Node node) {
    freqmap[node.freq].push_front(node);
    keymap[node.key] = freqmap[node.freq].begin();
    size++;
  }

  /**
   * @brief 删除当前key对应的node，并返回一个freq+1的新node。
   *
   * @param key
   * @return Node&
   */
  Node earse(int key) {
    auto node = keymap[key];
    int val = node->val, freq = node->freq;
    // 将当前key使用次数加一，释放当前node,判断是否释放当前freqlist
    freqmap[freq].erase(node);
    keymap.erase(key);
    if (freqmap[freq].empty()) {
      freqmap.erase(freq);
      if (freq == minfreq) { minfreq++; }
    }
    size--;
    return Node(key, val, freq + 1);
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

int main(int argc, char const* argv[]) {
  LFUCache lFUCache(2);
  lFUCache.put(1, 1);
  lFUCache.put(2, 2);
  cout << lFUCache.get(1) << endl;

  lFUCache.put(3, 3);

  cout << lFUCache.get(2) << endl;
  cout << lFUCache.get(3) << endl;

  lFUCache.put(4, 4);

  cout << lFUCache.get(1) << endl;
  cout << lFUCache.get(3) << endl;

  cout << lFUCache.get(4) << endl;

  return 0;
}
