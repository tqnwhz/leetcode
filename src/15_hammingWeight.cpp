#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int cnt = 0;
    while (n) {
      n &= n - 1;
      cnt++;
    }
    return cnt;
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
