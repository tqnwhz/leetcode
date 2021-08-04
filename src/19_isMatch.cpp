#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool isMatch(string s, string p) {
    vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
    dp[0][0] = true;

    auto charMatch = [&](int i, int j) {
      if (i == 0) {
        return false;
      }
      return p[j - 1] == '.' || s[i - 1] == p[j - 1];
    };
    for (int i = 0; i <= s.size(); i++) {
      for (int j = 1; j <= p.size(); j++) {
        if (p[j - 1] == '*') {
          if (charMatch(i, j - 1)) {
            dp[i][j] = dp[i - 1][j] || dp[i][j - 2];
          } else {
            dp[i][j] = dp[i][j - 2];
          }
        } else {
          if (charMatch(i, j)) {
            dp[i][j] = dp[i - 1][j - 1];
          }
        }
      }
    }
    return dp[s.size()][p.size()];
  }
};

int main() {
  Solution s;
  cout << s.isMatch("aa", "a*") << endl;
  system("pause");
  return 0;
}
