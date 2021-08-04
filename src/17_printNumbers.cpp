#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<char> nums{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

  void dfs(string now, int n, vector<string> &res) {
    if (n <= 0) {
      return;
    }
    if (n == 1) {
      for (auto c : nums) {
        auto tmp = now + c;
        auto pos = tmp.find_first_not_of("0");
        if (pos != string::npos) {
          res.push_back(tmp.substr(pos));
        }
      }
    } else {
      for (auto c : nums) {
        dfs(now + c, n - 1, res);
      }
    }
  }

  vector<int> printNumbers(int n) {
    vector<string> stringResult;
    dfs("", n, stringResult);
    vector<int> res;
    for (auto &s : stringResult) {
      res.push_back(stoi(s));
    }
    return res;
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
