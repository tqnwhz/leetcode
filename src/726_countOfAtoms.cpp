#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  map<string, int> counts;

  void update(string name, int cnt) {
    if (counts.count(name) == 0) {
      counts[name] = cnt;
    } else {
      counts[name] += cnt;
    }
  }

  void exec(string formula, int times = 1) {
    if (formula.length() == 0) {
      return;
    }
    for (int i = 0; i < formula.length(); i++) {
      if (formula[i] >= 'A' && formula[i] <= 'Z') {
        int j = i + 1;
        while (j < formula.length() && formula[j] >= 'a' && formula[j] <= 'z') {
          j++;
        }
        auto name = formula.substr(i, j - i);
        i = j;
        while (j < formula.length() && formula[j] >= '0' && formula[j] <= '9') {
          j++;
        }
        int cnt = 1;
        if (j != i) {
          cnt = stoi(formula.substr(i, j - i));
        }
        update(name, cnt * times);
        i = j - 1;
      } else if (formula[i] == '(') {
        int cnt = 1;
        int j = i + 1;
        while (cnt != 0) {
          if (formula[j] == '(') {
            cnt++;
          } else if (formula[j] == ')') {
            cnt--;
          }
          j++;
        }
        int start = j;
        while (j < formula.length() && formula[j] >= '0' && formula[j] <= '9') {
          j++;
        }
        cnt = 1;
        if (j != start) {
          cnt = stoi(formula.substr(start, j - start));
        }
        exec(formula.substr(i + 1, start - i - 1), cnt * times);
        i = j - 1;
      }
    }
  }

  string countOfAtoms(string formula) {
    exec(formula);

    string res;
    for (auto [name, cnt] : counts) {
      res = res + name;
      if (cnt > 1) {
        res += to_string(cnt);
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  cout << s.countOfAtoms("Be32") << endl;
  system("pause");
  return 0;
}
