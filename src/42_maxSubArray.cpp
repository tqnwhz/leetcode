#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int res = nums[0], pre = 0;
    for (auto& x : nums) {
      pre = max(pre + x, x);
      res = max(res, pre);
    }
    return res;
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
