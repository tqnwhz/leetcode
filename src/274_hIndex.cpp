#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int hIndex(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    int hIndex = 0, n = citations.size();
    for (hIndex = n; hIndex >= 1; hIndex--) {
      if (citations[n - hIndex] >= hIndex) {
        break;
      }
    }
    return hIndex;
  }
};

class Solution1 {
 public:
  int hIndex(vector<int> citations) {
    int hIndex = 0, n = citations.size();
    vector<int> counts(n + 1, 0);
    vector<int> result(n, 0);
    for (auto c : citations) {
      counts[min(c, n)]++;
    }
    for (int i = 1; i <= n; i++) {
      counts[i] = counts[i] + counts[i - 1];
    }
    for (int i = n - 1; i >= 0; i--) {
      int c = min(citations[i], n);
      result[counts[c] - 1] = c;
      counts[c]--;
    }
    for (hIndex = n; hIndex >= 1; hIndex--) {
      if (result[n - hIndex] >= hIndex) {
        return hIndex;
      }
    }

    return hIndex;
  }
};

int main() {
  Solution1 s;
  cout << s.hIndex({3, 0, 6, 1, 5}) << endl;
  system("pause");
  return 0;
}
