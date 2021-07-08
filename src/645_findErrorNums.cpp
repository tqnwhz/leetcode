#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> findErrorNums(vector<int>& nums) {
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      while (nums[i] != nums[nums[i] - 1]) {
        swap(nums[i], nums[nums[i] - 1]);
      }
    }
    for (int i = 0; i < nums.size(); i++) {
      if (i != nums[i] - 1 && nums[i] == nums[nums[i] - 1]) {
        res.push_back(nums[i]);
        res.push_back(i + 1);
        break;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> arr = {2, 3, 2};
  for (auto c : s.findErrorNums(arr)) {
    cout << c << ' ';
  }
  cout << endl;
  system("pause");
  return 0;
}
