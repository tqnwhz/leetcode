#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;
class Solution {
 public:
  vector<int> fibs = {0, 1};
  int fib(int n) {
    if (fibs.size() <= n) {
      int res = (fib(n - 1) + fib(n - 2)) % 1000000007;
      fibs.push_back(res);
      return res;
    }
    return fibs[n];
  }
};
int main() {
  Solution s;

  cout << s.fib(5) << endl;
  return 0;
}
