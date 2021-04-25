#include <gtest/gtest.h>

#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

/**
 * @brief 获取不同长度的可变参数，打印参数的个数
 *
 * @tparam T
 * @param args
 */
template <typename... T>
void func(T... args) {
  cout << sizeof...(args) << endl;
}

TEST(test_varg, basic) {
  func();
  func(1);
  func(1, 2);
  func(1, 2, '3', vector<int>{3});
}
/**
 [ RUN      ] test_varg.basic
  0
  1
  2
  4
  [       OK ] test_varg.basic (0 ms)
 */

void print() { cout << " ;" << endl; }
template <typename T>
void print(T v) {
  cout << v << " ";
}
template <typename T, typename... Args>
void print(T head, Args... args) {
  print(head);
  cout << "remain size : " << sizeof...(args) << endl;
  print(args...);
}

TEST(test_varg, recursive_print_error_version) {
  print();
  print(1, 2);
  print(1, 2.3, '3');
}
/**
 [ RUN      ] test_varg.recursive_print
  ;
  1 remain size : 1
  2 1 remain size : 2
  2.3 remain size : 1
  3 [       OK ] test_varg.recursive_print (0 ms)
 */

void ic() { cout << " ; " << endl; }
template <typename T, typename... Args>
void ic(T head, Args... args) {
  cout << head << " ";
  ic(args...);
}

template <typename T>
T sums() {
  return (T)(-2);
}
template <typename T, typename... Ts>
T sums(T v, Ts... vs) {
  return v + sums<T>(vs...);
}

TEST(test_varg, recursive_print_right_version) {
  ic(sums(1, 2));
  ic(sums(1, 2.3, 3.5));
  ic(sums(2.3, 1, 3.5));
}
/*
[ RUN      ] test_varg.recursive_print_right_version
1  ;
4  ;
4.8  ;
[       OK ] test_varg.recursive_print_right_version (0 ms)
*/

template <typename T>
int toint(T t) {
  return (int)t;
}

template <typename... Args>
vector<int> toints(Args... args) {
  vector<int> arr = {toint(args)...};
  return arr;
}

TEST(test_varg, expand_right_version) {
  auto arr = toints(1.2, 2.4, 3.6, 4.7);
  for (size_t i = 0; i < arr.size(); i++) { ic(arr[i]); }
}
