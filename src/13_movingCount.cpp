#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int getSum(int x) {
    int res = 0;
    while (x) {
      res += x % 10;
      x /= 10;
    }
    return res;
  }

  int movingCount(int m, int n, int k) {
    int cnt = 0;
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    list<pair<int, int>> que{{0, 0}};
    while (!que.empty()) {
      auto [x, y] = que.front();
      que.pop_front();
      if (!visited[x][y] && getSum(x) + getSum(y) <= k) {
        cnt++;
        visited[x][y] = true;
        if (x < m - 1) {
          que.push_back({x + 1, y});
        }
        if (y < n - 1) {
          que.push_back({x, y + 1});
        }
      }
    }
    return cnt;
  }
};

int main() {
  Solution s;
  cout << s.movingCount(1, 3, 1) << endl;
  system("pause");
  return 0;
}
