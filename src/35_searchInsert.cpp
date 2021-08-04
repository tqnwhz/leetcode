#include <bits/stdc++.h>

using namespace std;

/*
二分查找的取等：
若取等后不会死循环，则应该取等
*/

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (nums[mid] > target) {
        r = mid - 1;
      } else if (nums[mid] < target) {
        l = mid + 1;
      } else {
        return mid;
      }
    }
    return l;
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
