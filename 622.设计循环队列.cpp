/*
 * @lc app=leetcode.cn id=622 lang=cpp
 *
 * [622] 设计循环队列
 */
#include "commom.hpp"

// @lc code=start
class MyCircularQueue {
 private:
  int head, tail, capacity;
  bool empty, full;
  vector<int> q;
  int next(int idx) { return (idx + 1) % capacity; }

 public:
  MyCircularQueue(int k)
      : q(k), capacity(k), head(0), tail(0), empty(true), full(false) {}

  bool enQueue(int value) {
    if (isFull()) return false;

    if (not empty) tail = next(tail);
    q[tail] = value;

    if (empty) empty = false;
    if (next(tail) == head) full = true;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) return false;

    if (head == tail)
      empty = true;
    else
      head = next(head);

    if (full) full = false;
    return true;
  }

  int Front() {
    if (empty) return -1;
    return q[head];
  }

  int Rear() {
    if (empty) return -1;

    return q[tail];
  }

  bool isEmpty() { return empty; }

  bool isFull() { return full; }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

int main(int argc, char const* argv[]) {
  MyCircularQueue q(6);
  ic(q.enQueue(6));
  ic(q.Rear());
  ic(q.Rear());
  ic(q.deQueue());
  ic(q.enQueue(5));
  ic(q.Rear());
  ic(q.deQueue());
  ic(q.Front());
  ic(q.deQueue());
  ic(q.deQueue());
  ic(q.deQueue());
  return 0;
}

