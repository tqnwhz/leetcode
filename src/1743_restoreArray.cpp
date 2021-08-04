#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> restoreArray(vector<vector<int>> &adjacentPairs) {
    unordered_map<int, vector<int>> graph;
    int n = adjacentPairs.size() + 1;
    vector<int> res;
    for (auto &p : adjacentPairs) {
      graph[p[0]].push_back(p[1]);
      graph[p[1]].push_back(p[0]);
    }
    for (auto &[v, neibors] : graph) {
      if (neibors.size() == 1) {
        res.push_back(v);
        res.push_back(neibors[0]);
        break;
      }
    }
    while (res.size() < n) {
      int left = res[res.size() - 2], now = res.back();
      for (auto &neibor : graph[now]) {
        if (neibor != left) {
          res.push_back(neibor);
          break;
        }
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<vector<int>> arr{{2, 1}, {3, 4}, {3, 2}};
  for (auto v : s.restoreArray(arr)) cout << v << ' ';
  cout << endl;
  system("pause");
  return 0;
}
