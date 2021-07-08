#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int numWays(int n, vector<vector<int>>& relation, int k) {
    vector<vector<int>> graph(n);
    for (auto& e : relation) {
      graph[e[0]].push_back(e[1]);
    }
    list<int> que = {0};
    int res = 0;
    while (k--) {
      int r = que.size();
      for (int i = 0; i < r; i++) {
        auto v = que.front();
        que.insert(que.end(), graph[v].begin(), graph[v].end());
        que.pop_front();
      }
    }
    for (auto v : que) {
      res += v == n - 1;
    }
    return res;
  }
};

class Solution1 {
 public:
  int numWays(int n, vector<vector<int>>& relation, int k) {
    vector<vector<int>> graph(n);
    vector<int> startNeibors;
    for (auto& e : relation) {
      graph[e[1]].push_back(e[0]);
      if (e[0] == 0) {
        startNeibors.push_back(e[1]);
      }
    }
    vector<vector<int>> dp(k, vector<int>(n, 0));
    for (auto neibor : startNeibors) {
      dp[0][neibor] = 1;
    }
    for (int i = 1; i < k; i++) {
      for (int j = 0; j < n; j++) {
        for (auto neibor : graph[j]) {
          dp[i][j] += dp[i - 1][neibor];
        }
      }
    }
    return dp[k - 1][n - 1];
  }
};

int main() {
  Solution1 s;
  vector<vector<int>> relation = {{0, 2}, {2, 1}};
  cout << s.numWays(3, relation, 2) << endl;
  return 0;
}
