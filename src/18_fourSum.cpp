#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  const static int numCount = 3;
  int nextVal(vector<int> nums, int now, bool reverse = false) {
    int next;
    if (!reverse) {
      next = now + 1;
      while (next < nums.size() && nums[next] == nums[now]) next++;
    } else {
      next = now - 1;
      while (next >= 0 && nums[next] == nums[now]) next--;
    }
    return next;
  }

  void dfs(vector<int>& nums, int target, vector<int>& tmp, int sum, int start,
           vector<vector<int>>& result) {
    int minSum = sum;
    for (int i = 0; i < numCount - tmp.size(); i++) {
      minSum += nums[i + start];
    }
    if (minSum > target) {
      return;
    }
    int maxSum = sum;
    for (int i = 0; i < numCount - tmp.size(); i++) {
      maxSum += nums[nums.size() - i - 1];
    }
    if (maxSum < target) {
      return;
    }
    if (tmp.size() == numCount - 2) {
      for (int i = start, j = nums.size() - 1; i < j;) {
        if (sum + nums[i] + nums[j] == target) {
          vector<int> res(tmp);
          res.push_back(nums[i]);
          res.push_back(nums[j]);
          result.push_back(res);
          i = nextVal(nums, i);
          j = nextVal(nums, j, true);
        } else if (sum + nums[i] + nums[j] < target) {
          i = nextVal(nums, i);
        } else {
          j = nextVal(nums, j, true);
        }
      }
    } else {
      for (int i = start; i <= nums.size() - (numCount - tmp.size());) {
        tmp.push_back(nums[i]);
        dfs(nums, target, tmp, sum + nums[i], i + 1, result);
        tmp.pop_back();
        i = nextVal(nums, i);
      }
    }
  }

  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    if (nums.size() < numCount) {
      return {};
    }
    sort(nums.begin(), nums.end());
    vector<int> tmp;
    vector<vector<int>> result;
    dfs(nums, target, tmp, 0, 0, result);
    return result;
  }
};

int main() {
  Solution s;
  vector<int> nums{-1, 0, 1, 2, -1, -4};
  for (auto& v : s.fourSum(nums, 0)) {
    for (auto n : v) {
      cout << n << ' ';
    }
    cout << endl;
  }
  return 0;
}
