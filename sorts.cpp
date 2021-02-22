#include "commom.hpp"

void bubbleSort(vector<int>& arr) {
  int n = arr.size();
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      // 把第一个元素送到最后之后,下一次就可以少送一次.
      if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
    }
  }
}

void bubbleSort2(vector<int>& arr) {
  /* 改良版,利用flag确定是不是已经有序了
   * 因为每次排序之后, [n-i,n] 这部分已经是有序的了
   * 那么如果在[0,n-i]没有出现过交换,那么前面部分也是有序的了
   */
  bool swapped = true;
  int n = arr.size();
  for (int i = 0; i < n - 1; i++) {
    if (not swapped) break;
    swapped = false;
    for (int j = 0; j < n - 1 - i; j++) {
      // 把第一个元素送到最后之后,下一次就可以少送一次.
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapped = true;
      }
    }
  }
}

void bubbleSort3(vector<int>& arr) {
  /* 改良版,利用flag确定是不是已经有序了
   * 因为每次排序之后, [n-i,n] 这部分已经是有序的了
   * 同时我们要从前面开始找到非有序序列的开始
   */
  int n = arr.size(), lastunsort = n - 1, lastsort = -1;
  bool swapped = true;
  while (swapped) {
    swapped = false;
    for (int j = 0; j < lastunsort; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapped = true;
        lastsort = j;
      }
    }
    // 把第一个元素向后送,他最后送到的位置之后都是有序的.
    lastunsort = lastsort;
  }
}

void selectionSort(vector<int>& arr) {
  /* 选择排序,每次选择在当前值后面最小的元素 */
  int n = arr.size(), minidx;
  for (int i = 0; i < n; i++) {
    minidx = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minidx]) { minidx = j; }
    }
    swap(arr[i], arr[minidx]);
  }
}
void selectionSort2(vector<int>& arr) {
  /* 选择排序2
   * 一次遍历我们可以找到最小值和最大值.
   */
  int n = arr.size(), minidx, maxidx;
  for (int i = 0; i < n / 2; i++) {
    maxidx = minidx = i;
    for (int j = i + 1; j < n - i; j++) {
      if (arr[j] < arr[minidx]) { minidx = j; }
      if (arr[j] > arr[maxidx]) { maxidx = j; }
    }
    if (maxidx == minidx) break;
    swap(arr[i], arr[minidx]);  // 最小的放最前面
    //最大值是i的时候,i刚刚被交换了,这里就修改掉.
    if (maxidx == i) { maxidx = minidx; }
    swap(arr[n - i - 1], arr[maxidx]);  // 最大的放最后面
  }
}

int partition(vector<int>& arr, int start, int end) {
  // TODO:
  // 从数组中随机选择一个数字,然后将比这个数小的放左边,大的放右边,返回中间值的索引
  // 先随机选择一个数字,增强随机性
  swap(arr[start], arr[start + (rand() % (end - start))]);
  int pivot = arr[start];
  int l = start + 1, r = end;
  // 当数组完全有序或者完全逆序的时候,每次一边只有一个元素被分出去,那么时间复杂度将达到On^2
  while (l < r) {
    // 左边都要比中值小
    while (l < r and arr[l] <= pivot) l++;
    // 右边边都要比中值大
    while (l < r and arr[r] >= pivot) r--;
    // 如果出现异常,交换l r
    if (l < r) { swap(arr[l++], arr[r--]); }
  }
  /* 最后处理中值,最后只有两种情况
   * [l][r]->[r][l]
   * [l]?[r]->[lr]
   */
  if (l == r and arr[r] > pivot) r--;
  swap(arr[start], arr[r]);
  return r;
}

void quickSort(vector<int>& arr, int start, int end) {
  if (start >= end) return;
  int middle = partition(arr, start, end);
  // 对左边区域快速排序
  quickSort(arr, start, middle - 1);
  // 对右边区域快速排序
  quickSort(arr, middle + 1, end);
}

void quickSort(vector<int>& arr) { quickSort(arr, 0, arr.size() - 1); }

int main() {
  vector<int> arr{-4, 0, 7, 4, 9, -5, -1, 0, -7, -1};
  auto arr2 = arr, arr3 = arr;
  // bubbleSort(arr);
  // ic(arr);
  selectionSort2(arr2);
  ic(arr2);
  quickSort(arr3);
  ic(arr3);
  // bubbleSort3(arr3);
  // ic(arr3);

  return 0;
}