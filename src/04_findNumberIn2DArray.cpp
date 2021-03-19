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

  bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    for (auto& m : matrix) {
      auto res = binSearch(m, 0, m.size() - 1, target);
      if (res != -1) {
        return true;
      }
    }
    return false;
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
