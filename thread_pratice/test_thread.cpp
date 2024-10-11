#include <barrier>
#include <commom.hpp>
#include <gtest/gtest.h>
#include <latch>
// #include <syncstream>
#include <thread>

using namespace std;

thread_local uint64_t bid;

std::mutex cout_mutex;

void increase_rage(const string name, const uint64_t cbid) {
  // modifying outside a lock is okay; this is a thread-local variable
  bid = cbid;
  std::lock_guard<std::mutex> lock(cout_mutex);
  std::cout << "thread " << name << " bid is " << bid << '\n';
}

TEST(test_thread, test_thread_local) {
  std::thread a(increase_rage, "a", bid++), b(increase_rage, "b", bid++);

  {
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "main thread bid is " << bid << '\n';
  }

  a.join();
  b.join();
}

volatile int g_i = 0;
std::mutex g_i_mutex; // 保护 g_i

void inner_increment() {
  const std::lock_guard<std::mutex> lock(g_i_mutex);
  g_i = g_i + 1;
}

/**
 * @brief lock guard 等同于在这个域中使用pthread的lock unlock.
 * @param iterations
 */
void saft_increment(const string name, int iterations) {
  // g_i_mutex 在锁离开作用域时自动释放
  while (iterations-- > 0) {
    inner_increment();
  }
  {
    const std::lock_guard<std::mutex> lock(g_i_mutex);
    std::cout << "线程 #" << name << ", g_i: " << g_i << '\n';
  }
}

void unsaft_increment(const string name, int iterations) {
  while (iterations-- > 0) {
    g_i = g_i + 1;
  }
  {
    const std::lock_guard<std::mutex> lock(g_i_mutex);
    std::cout << "线程 #" << name << ", g_i: " << g_i << '\n';
  }
}

/**
 * @brief 这个例子中safe inc在增加值前后会锁住这个区域,
 * 第一个线程打印的值时不是2000000,
 * 是因为这两个线程是交替执行,第一个线程增加1000000时,
 * 第二个线程增加了大约800000个. 然后整体还是增加2000000次
 * 而unsafe会没有加锁导致读g i的时候可能读到过去的值, 然后最终答应出来的g
 * i并不是2000000.
 *
 */
TEST(test_thread, test_lock_guard) {

  auto test = [](std::string_view fun_name, auto fun) {
    g_i = 0;
    std::cout << fun_name << ":\n前, g_i: " << g_i << '\n';
    {
      thread t1(fun, "t1", 1'000'000);
      thread t2(fun, "t2", 1'000'000);
      t1.join();
      t2.join();
    }
    std::cout << "后, g_i: " << g_i << "\n\n";
  };
  test("saft_increment", saft_increment);
  test("unsaft_increment", unsaft_increment);
}

struct Job {
  const std::string name;
  std::string product{"未工作"};
  std::thread action{};
};

/**
 * @brief test latch
 *  latch 只能使用一次. count down等于arrive, wait相当于等所有都arrive.
 */
TEST(test_thread, test_latch) {
  Job jobs[]{{"Annika"}, {"Buru"}, {"Chuck"}};

  std::latch work_done{std::size(jobs)};
  std::latch start_clean_up{1};

  auto work = [&](Job &my_job) {
    my_job.product = my_job.name + " 已工作";
    work_done.count_down();
    start_clean_up.wait();
    my_job.product = my_job.name + " 已清理";
  };

  std::cout << "工作启动... ";
  for (auto &job : jobs)
    job.action = std::thread{work, std::ref(job)};

  work_done.wait();

  std::cout << "完成:\n";
  for (auto const &job : jobs)
    std::cout << "  " << job.product << '\n';

  std::cout << "清理工作线程... ";
  start_clean_up.count_down();
  for (auto &job : jobs)
    job.action.join();

  std::cout << "完成:\n";
  for (auto const &job : jobs)
    std::cout << "  " << job.product << '\n';
}

TEST(test_thread, test_barrir) {

  const auto workers = {"Anil", "Busara", "Carl"};

  auto on_completion = []() noexcept {
    // 此处无需锁定
    static auto phase = "... 完成\n"
                        "清理...\n";
    std::cout << phase;
    phase = "... 完成\n";
  };

  std::barrier sync_point(std::ssize(workers), on_completion);

  auto work = [&](std::string name) {
    std::string product = "  " + name + " 已工作\n";
    std::cout << product; // OK, op<< 的调用是原子的
    sync_point.arrive_and_wait();

    product = "  " + name + " 已清理\n";
    std::cout << product;
    sync_point.arrive_and_wait();
  };

  std::cout << "启动...\n";
  std::vector<thread> threads;
  threads.reserve(std::size(workers));
  for (auto const &worker : workers)
    threads.emplace_back(work, worker);
  for (auto &t : threads)
    t.join();
}