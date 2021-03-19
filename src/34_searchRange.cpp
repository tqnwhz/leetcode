#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int binSearch(vector<int>& nums, int left, int right, int target) {
    if (left > right || nums[left] > target || nums[right] < target) {
      return -1;
    }
    int mid = (left + right) / 2;
    while (left <= right) {
      mid = (left + right) / 2;
      if (nums[mid] > target) {
        right = mid - 1;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        return mid;
      }
    }
    return mid <= right && nums[mid] == target ? mid : -1;
  }

  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.empty()) {
      return {-1, -1};
    }
    int l = 0, r = nums.size() - 1;
    int mid = binSearch(nums, l, r, target);
    vector<int> res = {mid, mid};
    int t = mid;
    while ((t = binSearch(nums, l, t - 1, target)) != -1) {
      res[0] = t;
    }
    t = mid;
    while ((t = binSearch(nums, t + 1, r, target)) != -1) {
      res[1] = t;
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> nums = {5, 7, 7, 8, 8, 10};

  auto res = s.searchRange(nums, 6);
  for (auto r : res) {
    cout << r << ",";
  }
  cout << endl;
  return 0;
}
