/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include "commom.hpp"
// @lc code=start
class MyQueue {
 private:
  stack<int> a, b;
  int bfront;

 public:
  /** Initialize your data structure here. */
  MyQueue() {}

  /** Push element x to the back of queue. */
  void push(int x) {
    if (b.empty()) {
      bfront = x;
    }
    b.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    if (a.empty()) {
      while (b.size()) {
        a.push(b.top());
        b.pop();
      }
    }
    int _front = a.top();
    a.pop();
    return _front;
  }

  /** Get the front element. */
  int peek() {
    if (a.empty()) {
      return bfront;
    }

    return a.top();
  }

  /** Returns whether the queue is empty. */
  bool empty() { return a.empty() and b.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

int main(int argc, char const* argv[]) {
  MyQueue q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  ic(q.pop());
  q.push(5);
  ic(q.pop());
  ic(q.pop());
  ic(q.pop());
  ic(q.pop());
  ic(q.empty());
  return 0;
}
