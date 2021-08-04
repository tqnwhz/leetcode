#include <bits/stdc++.h>

using namespace std;

class TimeMap {
 public:
  /** Initialize your data structure here. */

  unordered_map<string, vector<pair<int, string>>> mp;

  TimeMap() {}

  void set(string key, string value, int timestamp) {
    mp[key].push_back({timestamp, value});
  }

  string get(string key, int timestamp) {
    auto& values = mp[key];
    int l = 0, r = values.size() - 1;
    while (l <= r) {
      int mid = (r - l) / 2 + l;
      if (values[mid].first < timestamp) {
        l = mid + 1;
      } else if (values[mid].first > timestamp) {
        r = mid - 1;
      } else {
        l = r = mid;
        break;
      }
    }
    return r >= 0 ? values[r].second : "";
  }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main() {
  TimeMap s;

  system("pause");
  return 0;
}
