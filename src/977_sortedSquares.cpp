#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    int l = -1;

    for (int i = 0; i < nums.size() - 1; i++) {
      if (nums[i] < 0 && nums[i + 1] >= 0) {
        l = i;
        break;
      }
    }
    vector<int> res;
    if (l == -1) {
      if (nums[0] >= 0) {
        for (auto num : nums) {
          res.push_back(num * num);
        }
        return res;
      } else {
        for (int i = nums.size() - 1; i >= 0; i--) {
          res.push_back(nums[i] * nums[i]);
        }
        return res;
      }
    }
    int r = l + 1;
    while (res.size() < nums.size()) {
      if (l >= 0 && r < nums.size()) {
        res.push_back(min(nums[l] * nums[l], nums[r] * nums[r]));
        if (-nums[l] > nums[r]) {
          r++;
        } else {
          l--;
        }
      } else if (l >= 0) {
        res.push_back(nums[l] * nums[l--]);
      } else {
        res.push_back(nums[r] * nums[r++]);
      }
    }
    return res;
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
