#include <bits/stdc++.h>

using namespace std;

bool isBadVersion(int version);

class Solution {
 public:
  int firstBadVersion(int n) {
    int l = 1, r = n;
    int mid;
    while (l <= r) {
      mid = (r - l) / 2 + l;
      if (isBadVersion(mid)) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return isBadVersion(mid) ? mid : mid + 1;
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
