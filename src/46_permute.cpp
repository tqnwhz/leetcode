#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void dfs(vector<int> &nums, vector<int> &tmp, vector<vector<int>> &res,
           vector<bool> &visited) {
    if (nums.size() == tmp.size()) {
      res.push_back(tmp);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (!visited[i]) {
        visited[i] = true;
        tmp.push_back(nums[i]);
        dfs(nums, tmp, res, visited);
        tmp.pop_back();
        visited[i] = false;
      }
    }
  }

  vector<vector<int>> permute(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> res;
    vector<bool> visited(n, false);
    vector<int> tmp;
    dfs(nums, tmp, res, visited);
    return res;
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
