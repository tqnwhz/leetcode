#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  double myPow(double x, int n) {
    if (n < 0) {
      return myPow(1 / x, -(n + 1)) * 1 / x;
    } else if (n == 0) {
      return 1;
    }
    if (n % 2 == 0) {
      return myPow(x * x, n / 2);
    }
    return x * myPow(x * x, n / 2);
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
