#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) i--;
    if (i >= 0) {
      int j = nums.size() - 1;
      for (; nums[j] <= nums[i]; j--)
        ;
      swap(nums[j], nums[i]);
    }
    reverse(nums.begin() + i + 1, nums.end());
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
