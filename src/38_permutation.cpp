#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void rec(string s, string tmp, vector<bool> visited,
           unordered_set<string>& result) {
    if (tmp.size() == s.size()) {
      result.insert(tmp);
      return;
    }
    for (int i = 0; i < s.size(); i++) {
      if (!visited[i]) {
        visited[i] = true;
        rec(s, tmp + s[i], visited, result);
        visited[i] = false;
      }
    }
  }

  vector<string> permutation(string s) {
    unordered_set<string> result;
    vector<bool> visited(s.size(), false);
    rec(s, "", visited, result);
    return vector<string>(result.begin(), result.end());
  }
};

int main() {
  Solution s;
  for (auto c : s.permutation("abc")) cout << c << endl;
  system("pause");
  return 0;
}
