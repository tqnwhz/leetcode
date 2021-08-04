#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    if (s.size() < 2) {
      return s;
    }
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    for (int i = 0; i < s.size(); i++) {
      dp[i][i] = true;
    }
    int start = 0, length = 0;
    for (int len = 2; len <= s.size(); len++) {
      for (int i = 0; i < s.size() - len + 1; i++) {
        if (len == 2) {
          dp[i][i + len - 1] = s[i] == s[i + len - 1];
        } else {
          dp[i][i + len - 1] = s[i] == s[i + len - 1] && dp[i + 1][i + len - 2];
        }
        if (dp[i][i + len - 1]) {
          start = i;
          length = len;
        }
      }
    }
    return length > 0 ? s.substr(start, length) : s.substr(0, 1);
  }
};

int main() {
  Solution s;
  cout << s.longestPalindrome("ac") << endl;
  system("pause");
  return 0;
}
