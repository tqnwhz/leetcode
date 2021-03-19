#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    map<string, vector<set<string>>> accountMap;
    bool change = false;
    for (auto& vc : accounts) {
      auto name = vc[0];
      if (!accountMap.count(name)) {
        accountMap[name] = vector<set<string>>();
      }
      auto& s = accountMap[name];
      auto flag = false;
      int j = 0;
      for (int i = 1; i < vc.size(); i++) {
        for (j = 0; j < s.size(); j++) {
          if (s[j].count(vc[i])) {
            flag = true;
            break;
          }
          if (flag) {
            break;
          }
        }
      }
      if (flag) {
        s[j].insert(vc.begin() + 1, vc.end());
        change = true;
      } else {
        auto new_s = set<string>(vc.begin() + 1, vc.end());
        s.push_back(new_s);
      }
    }
    vector<vector<string>> res;
    for (auto& p : accountMap) {
      for (auto m : p.second) {
        auto mail_vector = vector<string>(m.begin(), m.end());
        mail_vector.insert(mail_vector.begin(), p.first);
        res.push_back(mail_vector);
      }
    }
    return change ? accountsMerge(res) : res;
  }
};

int main() {
  Solution s;
  vector<vector<string>> accounts = {
      {"John", "johnsmith@mail.com", "john00@mail.com"},
      {"John", "johnnybravo@mail.com"},
      {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
      {"Mary", "mary@mail.com"},
  };
  for (auto p : s.accountsMerge(accounts)) {
    for (auto n : p) {
      cout << n << " ";
    }
    cout << endl;
  }

  return 0;
}
