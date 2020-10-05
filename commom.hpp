#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

template <typename K, typename V>
void pmap(const map<K, V>& dict) {
  for (auto&& item : dict) {
    cout << item.first << ' ' << item.second << ',';
  }
  cout << endl;
}

template <typename V>
void pvec(const vector<V>& v) {
  for (auto&& item : v) {
    cout << item << ' ';
  }
  cout << endl;
}

template <typename T>
void pscalr(const T& t) {
  cout << t << endl;
}

template <typename T, typename... Args>
void pscalr(const T& t, Args... args) {
  cout << t << ", ";
  pscalr(args...); 
}