#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class UnionSet {
 public:
  vector<int> parent;
  UnionSet(int length) {
    for (int i = 0; i < length; i++) {
      parent.push_back(i);
    }
  }

  int find(int x) {
    int r = x;
    while (parent[r] != r) {
      r = parent[r];
    }
    // while (parent[x] != x) {
    //   int p = parent[x];
    //   parent[x] = r;
    //   x = p;
    // }
    return r;
  }

  void merge(int l, int r) { parent[find(l)] = find(r); }
  bool same_root(int l, int r) { return find(l) == find(r); }
};

class Edge {
 public:
  int start;
  int end;
  int len;
  Edge(int start, int end, int len) : start(start), end(end), len(len) {}
  bool operator<(Edge& other) const { return len < other.len; }
  void _print() {
    cout << "add edge : "
         << "( " << start << ", " << end << ", " << len << ")" << endl;
  }
};

class Solution {
 public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    UnionSet us(points.size());
    vector<Edge> edges;
    for (int i = 0; i < points.size(); i++) {
      for (int j = i + 1; j < points.size(); j++) {
        edges.push_back(Edge(i, j,
                             abs(points[i][0] - points[j][0]) +
                                 abs(points[i][1] - points[j][1])));
      }
    }
    sort(edges.begin(), edges.end());
    int res = 0;
    for (auto& e : edges) {
      if (!us.same_root(e.start, e.end)) {
        res += e.len;
        us.merge(e.start, e.end);
      }
    }
    return res;
  }
};
int main() {
  Solution s;
  vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
  cout << s.minCostConnectPoints(points) << endl;
  system("pause");
  return 0;
}
