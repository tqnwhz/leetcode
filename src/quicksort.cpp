#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>& a, int left, int right) {
  int x = a[right];
  int p = left;
  for (int i = left; i < right; i++) {
    if (a[i] <= x) {
      swap(a[p++], a[i]);
    }
  }
  swap(a[p], a[right]);
  return p;
}
void quicksort(vector<int>& nums, int left, int right) {
  if (left < right) {
    int i = partition(nums, left, right);
    quicksort(nums, i + 1, right);
    quicksort(nums, left, i - 1);
  }
}

void heap_adjust(vector<int>& a, int i, int len) {
  int lc = 2 * i + 1;
  int rc = 2 * i + 2;
  int maxindex = i, tmp;
  if (lc < len && a[lc] > a[maxindex]) maxindex = lc;
  if (rc < len && a[rc] > a[maxindex]) maxindex = rc;

  if (maxindex != i) {
    swap(a[i], a[maxindex]);
    heap_adjust(a, maxindex, len);  //递归调整被换节点的子树
  }
}

void heap_sort(vector<int>& a) {
  int tmp = 0;
  int len = a.size();
  // make_heap
  for (int i = (len - 1) / 2; i >= 0;
       i--) {  // len / 2 - 1是从下到上从右到左的第一个非叶子节点
    heap_adjust(a, i, len);
  }

  // sort
  for (int i = len - 1; i >= 1; i--) {
    swap(a[i], a[0]);
    heap_adjust(a, 0, i);  //将前面的i-1个元素再调整为大顶堆
  }
}
int main() {
  vector<int> arr{5, -1, 7, 2, 0};
  heap_sort(arr);
  for (auto n : arr) {
    cout << n << ' ';
  }
  cout << endl;
  system("pause");
  return 0;
}
