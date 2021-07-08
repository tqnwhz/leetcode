#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(), costs.end());
    int res = 0;
    for (auto c : costs) {
      if (coins >= c) {
        coins -= c;
        res++;
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
