#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int findRepeatNumber(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      if (i != nums[i] && nums[i] == nums[nums[i]]) {
        return nums[i];
      }
      nums[nums[i]] = nums[i];
    }
    return 0;
  }
};

int main() {
  Solution s;
  vector<int> nums = {0, 1, 2, 3, 4, 11, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  cout << s.findRepeatNumber(nums) << endl;
  return 0;
}
