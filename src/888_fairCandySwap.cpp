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
  vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int sumA = 0, sumB = 0;
    for (auto a : A) sumA += a;
    for (auto b : B) sumB += b;
    int moreSum = sumB, lessSum = sumA;
    vector<int>&less = A, more = B;
    bool flag = false;
    if (sumB < sumA) {
      swap(more, less);
      swap(moreSum, lessSum);
      flag = true;
    }
    int i = 0, j = 0, gap = moreSum - lessSum;
    while (j < more.size() && i < less.size()) {
      if (more[j] - less[i] < gap / 2) {
        j++;
      } else if (more[j] - less[i] > gap / 2) {
        i++;
      } else {
        auto res1 = {more[j], less[i]};
        auto res2 = {less[i], more[j]};
        return flag ? res1 : res2;
      }
    }
    return {0, 0};
  }
};
int main() {
  Solution s;
  vector<int> A = {2}, B = {1, 3};
  for (auto c : s.fairCandySwap(A, B)) cout << c << endl;
  return 0;
}
