#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int partition(vector<int>& arr, int left, int right) {
    int val = arr[right];
    int p = left;
    for (int i = left; i < right; i++) {
      if (arr[i] <= val) {
        swap(arr[i], arr[p++]);
      }
    }
    swap(arr[right], arr[p]);
    return p;
  }

  //[left,right]
  void getLeastNumber(vector<int>& arr, int left, int right, int k) {
    if (left < right) {
      int r = rand() % (right - left + 1) + left;
      swap(arr[r], arr[right]);
      int p = partition(arr, left, right);
      if (k - 1 == p) {
        return;
      } else if (k - 1 < p) {
        getLeastNumber(arr, left, p - 1, k);
      } else {
        getLeastNumber(arr, p + 1, right, k);
      }
    }
  }

  vector<int> getLeastNumbers(vector<int>& arr, int k) {
    vector<int> res;
    getLeastNumber(arr, 0, arr.size() - 1, k);
    for (int i = 1; i <= k; i++) {
      res.push_back(arr[i - 1]);
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> arr{3, 2, 1};
  for (auto c : s.getLeastNumbers(arr, 2)) cout << c << endl;
  system("pause");
  return 0;
}
