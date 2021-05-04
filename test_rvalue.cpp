#include <gtest/gtest.h>

#include <iostream>
#include <vector>
using namespace std;

// void dosomething(vector<int>& arr) { arr[2] = 0; }

// TEST(rvalue, basic) {
//   vector<int> arr{1, 3, 4};
//   dosomething(arr);
//   dosomething(vector<int>{1, 3, 4});
// }
void dosomething(vector<int>& arr) { arr[2] = 0; }
void dosomething(vector<int>&& arr) { arr[2] = 0; }

TEST(rvalue, basic) {
  vector<int> arr{1, 3, 4};
  dosomething(arr);
  dosomething(vector<int>{1, 3, 4});
}

template <typename It>
auto fcn(It begin, It end) {
  for (auto it = begin; it != end; it++) { *it += 10; }
  return *begin;
}

template <typename It>
auto fcn2(It begin, It end) {
  for (auto it = begin; it != end; it++) { *it += 10; }
  return *begin;
}

TEST(templates, auto_get_value_type) {
  vector<int> a{2, 3, 4, 5};
  auto v = fcn(a.begin(), a.end());
  cout << v << endl;
}

TEST(stdc, stdc_defines) {
  cout << "Standard Clib: " << __STDC_HOSTED__ << endl;  // Standard Clib: 1
  cout << "Standard C: " << __STDC__ << endl;            // Standard C: 1
  // cout << "C Stardard version: " << __STDC_VERSION__ << endl;
  // cout << "ISO/IEC" << __STDC_ISO_10646__ << endl;       // ISO/IEC 200009
}

struct TestStruct {
  TestStruct() : name(__func__) {}
  const char* name;
};

TEST(stdc, func_defines) {
  TestStruct ts;
  cout << ts.name << endl;
}