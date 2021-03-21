#include "commom.hpp"
class Solution {
 public:
  int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
    auto le = [](pair<int, int>& a, pair<int, int>& b) {
      return a.first < b.first;
    };
    auto ge = [](pair<int, int>& a, pair<int, int>& b) {
      return a.first > b.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(ge)> sell(
        ge);
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(le)> buy(
        le);
    pair<int, int> t;
    for (auto&& order : orders) {
      if (order[2] == 0) {
        while (sell.size() and sell.top().first <= order[0] and order[1]) {
          t = sell.top(), sell.pop();
          if (t.second <= order[1]) {
            order[1] -= t.second;
          } else {
            t.second -= order[1];
            order[1] = 0;
            sell.push(t);
          }
        }
        if (order[1]) buy.push({order[0], order[1]});
      } else {
        while (buy.size() and buy.top().first >= order[0] and order[1]) {
          t = buy.top(), buy.pop();
          if (t.second <= order[1]) {
            order[1] -= t.second;
          } else {
            t.second -= order[1];
            order[1] = 0;
            buy.push(t);
          }
        }
        if (order[1]) sell.push({order[0], order[1]});
      }
    }
    int ans = 0;
    const int m = (1000000000 + 7);
    while (buy.size()) {
      t = buy.top(), buy.pop();
      ans = (ans + t.second) % m;
    }
    while (sell.size()) {
      t = sell.top(), sell.pop();
      ans = (ans + t.second) % m;
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  Mat<int> orders{
      {26, 7, 0},  {16, 1, 1}, {14, 20, 0}, {23, 15, 1},
      {24, 26, 0}, {19, 4, 1}, {1, 1, 0},
  };
  Solution s;
  Vec<int> nums{2, 1, 14, 23, 24, 1};
  priority_queue<int, vector<int>, greater<int>> q(nums.begin(), nums.end());
  while (q.size()) {
    ic(q.top());
    q.pop();
  }
  sort(nums.begin(), nums.end(), greater<int>());
  ic(nums);

  // ic(s.getNumberOfBacklogOrders(orders));
  return 0;
}
