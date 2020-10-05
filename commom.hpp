#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

template <typename K, typename V>
void pmap(const map<K, V> &dict)
{
  for (auto &&item : dict)
  {
    cout << item.first << ' ' << item.second << ',';
  }
  cout << endl;
}

template <typename V>
void pscalr(const V &v)
{
  cout << v << endl;
}

template <typename V>
void pvec(const vector<V> &v)
{
  for (auto &&item : v)
  {
    cout << item << ' ';
  }
  cout << endl;
}
