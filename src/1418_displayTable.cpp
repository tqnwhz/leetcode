#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<vector<string>> displayTable(vector<vector<string>>& orders) {
    map<int, map<string, int>> tableDishes;
    set<string> dishes;
    for (auto& order : orders) {
      auto name = order[0];
      auto table = stoi(order[1]);
      auto dish = order[2];
      if (!dishes.count(dish)) {
        dishes.insert(dish);
      }
      if (!tableDishes.count(table)) {
        tableDishes[table] = map<string, int>();
      }
      if (!tableDishes[table].count(dish)) {
        tableDishes[table][dish] = 0;
      }
      tableDishes[table][dish] += 1;
    }
    vector<vector<string>> res(1 + tableDishes.size(), vector<string>());
    res[0].push_back("Table");
    for (auto d : dishes) {
      res[0].push_back(d);
    }
    int i = 1;
    for (auto& [table, dishMap] : tableDishes) {
      res[i].push_back(to_string(table));
      for (auto dish : dishes) {
        if (dishMap.count(dish)) {
          res[i].push_back(to_string(dishMap[dish]));
        } else {
          res[i].push_back("0");
        }
      }
      i++;
    }
    return res;
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
