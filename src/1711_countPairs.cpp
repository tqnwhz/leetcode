#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static constexpr int MOD = 1'000'000'007;

  int countPairs(vector<int>& deliciousness) {
    unordered_map<int, int> counts;
    int res = 0;
    for (auto d : deliciousness) {
      for (int i = 0; i <= 21; i++) {
        int tmp = pow(2, i) - d;
        int count = counts.count(tmp) ? counts[tmp] : 0;
        res = (res + count) % MOD;
      }
      if (counts.count(d) == 0) {
        counts[d] = 0;
      }
      counts[d]++;
    }
    return res;
  }
};
int main() {
  Solution s;

  system("pause");
  return 0;
}
