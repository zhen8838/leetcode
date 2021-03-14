/*
 * @lc app=leetcode.cn id=705 lang=cpp
 *
 * [705] 设计哈希集合
 */
#include "commom.hpp"
// @lc code=start
class MyHashSet {
 private:
  int map[31251] = {0};

 public:
  /** Initialize your data structure here. */
  MyHashSet() {}

  void add(int key) {
    int idx = key / 32;
    int bidx = key % 32;
    map[idx] |= (1 << bidx);
  }

  void remove(int key) {
    int idx = key / 32;
    int bidx = key % 32;
    if (contains(key)) { map[idx] ^= (1 << bidx); }
  }

  /** Returns true if this set contains the specified element */
  bool contains(int key) {
    int idx = key / 32;
    int bidx = key % 32;
    return (map[idx] >> bidx) & 1;
  }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
// @lc code=end
