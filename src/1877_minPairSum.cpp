#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int minPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), res = -9999;
    for (int i = 0; i <= n / 2; i++) {
      res = max(nums[i] + nums[n - 1 - i], res);
    }
    return res;
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
