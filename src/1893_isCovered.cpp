#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b) { return a[0] < b[0]; }

class Solution {
 public:
  bool isCovered(vector<vector<int>> &ranges, int left, int right) {
    sort(ranges.begin(), ranges.end(), cmp);
    int now = 0;
    for (auto &range : ranges) {
      if (range[0] <= left && range[1] >= left) {
        left = range[1] + 1;
      }
    }
    return left > right;
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
