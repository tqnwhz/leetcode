#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static const int MOD = 1000000007;

  long long my_pow(int n, int m) {
    long long res = 1;
    while (m--) {
      res = (res * n) % MOD;
    }
    return res;
  }

  int cuttingRope(int n) {
    int res = 0;
    for (int m = 2; m <= n; m++) {
      int l = n / m;
      if (m * l == n) {
        res = max(res, (int)my_pow(l, m));
      } else {
        int rest = n;
        int r = l + 1;
        while (rest % r != 0) {
          rest -= l;
        }
        long long tmp = my_pow(l, (n - rest) / l) * my_pow(r, rest / r) % MOD;
        tmp %= MOD;
        res = max(res, (int)tmp);
      }
    }
    return res;
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
