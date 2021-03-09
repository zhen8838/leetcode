/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include "commom.hpp"
// @lc code=start
class MinHeap {
 private:
  vector<int> arr;
  int capa;
  int size;

 public:
  MinHeap(int n) : capa(n), size(0), arr(n + 2, 0) {}
  void push(int v) {
    size++;
    arr[size] = v;
    int child = size;
    int parent = child / 2;
    while (arr[child] < arr[parent] and child > 1) {
      swap(arr[parent], arr[child]);
      child = parent;
      parent = child / 2;
    }
    if (size > capa) { pop(); }
  }
  int pop() {
    int tmp = arr[1];
    arr[1] = arr[size];
    size--;
    int parent = 1;
    // 保证有子树
    while (parent < size and parent <= size / 2) {
      int left = parent * 2, right = left + 1;
      if (arr[parent] > arr[left] or arr[parent] > arr[right]) {
        if (arr[left] < arr[right]) {
          swap(arr[left], arr[parent]);
          parent = left;
        } else {
          swap(arr[right], arr[parent]);
          parent = right;
        }
      } else {
        break;
      }
    }
    return tmp;
  }

  int top() { return arr[1]; }
};

class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    auto maxheap = MinHeap(k);
    for (int i = 0; i < nums.size(); i++) { maxheap.push(nums[i]); }
    return maxheap.top();
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> nums = {3, 2, 1, 5, 6, 4};
  IC(s.findKthLargest(nums, 2));
  return 0;
}
