/*
 * @lc app=leetcode.cn id=1226 lang=cpp
 *
 * [1226] 哲学家进餐
 */
#include <mutex>

#include "commom.hpp"
// @lc code=start
class DiningPhilosophers {
 private:
  pthread_mutex_t forks[5];

 public:
  DiningPhilosophers() {
    // 启动互斥量
    for (size_t i = 0; i < 5; i++) {
      pthread_mutex_init(&forks[i], nullptr);
    }
  }
  void wantsToEat(int philosopher, function<void()> pickLeftFork,
                  function<void()> pickRightFork, function<void()> eat,
                  function<void()> putLeftFork, function<void()> putRightFork) {
    int left_hand = philosopher;             // 默认拿左边叉子
    int right_hand = (philosopher + 1) % 5;  // 对于4号,拿右边叉子编号为0
    int pick_left = 1, pick_right = 1;
    while (pick_left || pick_right) {
      /* 如果是被锁定的情况下就先等待解锁 */
      if (pick_left == 0) {
        pthread_mutex_unlock(&forks[left_hand]);
      }
      if (pick_right == 0) {
        pthread_mutex_unlock(&forks[right_hand]);
      }
      /* 解锁完成后锁定当前叉子,进行两个 */
      pick_left = pthread_mutex_trylock(&forks[left_hand]);
      pick_right = pthread_mutex_trylock(&forks[right_hand]);
    }
    pickLeftFork();
    pickRightFork();
    eat();
    putLeftFork();
    putRightFork();
    pthread_mutex_unlock(&forks[left_hand]);  //全部解锁
    pthread_mutex_unlock(&forks[right_hand]);
  }
};
// @lc code=end
