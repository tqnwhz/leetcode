#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int l = 0, r = citations.size() - 1;
    while (l <= r) {
      int mid = (r - l) / 2 + l;
      int hIndex = citations.size() - mid;

      if (citations[mid] >= hIndex) {
        r = mid - 1;
      } else if (citations[mid] < hIndex) {
        l = mid + 1;
      }
    }
    return citations.size() - l;
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
