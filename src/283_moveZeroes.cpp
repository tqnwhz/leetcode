#include <bits/stdc++.h>

using namespace std;

class Solution1 {
 public:
  void moveZeroes(vector<int>& nums) {
    for (int left = 0, right = 0; right < nums.size(); right++) {
      if (nums[right]) {
        swap(nums[right], nums[left++]);
      }
    }
  }
};

class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0, j = 0; i < n && j < n; i++) {
      while (i < n && nums[i] != 0) {
        i++;
      }
      if (i >= n) {
        break;
      }
      j = i + 1;
      while (j < n && nums[j] == 0) {
        j++;
      }
      if (j >= n) {
        break;
      }
      swap(nums[i], nums[j]);
    }
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
