#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) { return a.second > b.second; }

class Solution {
 public:
  string frequencySort(string s) {
    vector<int> counts(256, 0);
    for (auto c : s) {
      counts[c]++;
    }
    vector<pair<int, int>> arr;
    for (int i = 0; i < counts.size(); i++) {
      arr.push_back({i, counts[i]});
    }
    sort(arr.begin(), arr.end(), cmp);
    string res;
    for (auto &p : arr) {
      res += string(p.second, p.first);
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.frequencySort("tree") << endl;
  system("pause");
  return 0;
}
