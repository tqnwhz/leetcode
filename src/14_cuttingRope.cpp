#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int cuttingRope(int n) {
    int res = 0;
    for (int m = 2; m <= n; m++) {
      int l = n / m;
      if (m * l == n) {
        res = max(res, (int)pow(l, m));
      } else {
        int rest = n;
        int r = l + 1;
        while (rest % r != 0) {
          rest -= l;
        }
        res = max(res, (int)pow(l, (n - rest) / l) * (int)pow(r, rest / r));
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.cuttingRope(10) << endl;
  system("pause");
  return 0;
}
