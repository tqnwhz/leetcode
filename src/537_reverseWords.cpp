#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string reverseWords(string s) {
    int st = 0;
    string res;
    for (int j = 0; j < s.size(); j++) {
      if (s[j] == ' ') {
        reverse(s.begin() + st, s.begin() + j);
        st = j + 1;
      }
    }
    reverse(s.begin() + st, s.end());
    return s;
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
