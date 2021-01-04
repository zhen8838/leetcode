/*
 * @lc app=leetcode.cn id=1114 lang=cpp
 *
 * [1114] 按序打印
 */
#include <time.h>

#include <mutex>
using namespace std;

// @lc code=start
class Foo {
 private:
  pthread_mutex_t locks[3];

 public:
  Foo() {
    for (size_t i = 0; i < 3; i++) {
      pthread_mutex_init(&locks[i], nullptr);
    }
    pthread_mutex_lock(&locks[1]);
    pthread_mutex_lock(&locks[2]);
  }

  void first(function<void()> printFirst) {
    // printFirst() outputs "first". Do not change or remove this line.
    pthread_mutex_lock(&locks[0]);
    printFirst();
    pthread_mutex_unlock(&locks[1]);
  }

  void second(function<void()> printSecond) {
    // printSecond() outputs "second". Do not change or remove this line.
    pthread_mutex_lock(&locks[1]);
    printSecond();
    pthread_mutex_unlock(&locks[2]);
  }

  void third(function<void()> printThird) {
    // printThird() outputs "third". Do not change or remove this line.
    pthread_mutex_lock(&locks[2]);
    printThird();
    pthread_mutex_unlock(&locks[0]);
  }
};
// @lc code=end

int main(int argc, char const* argv[]) { 
  
  return 0; }
