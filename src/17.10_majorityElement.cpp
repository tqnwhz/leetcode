#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int majorityElement(vector<int> nums) {
    int candicate = 0, count = 0;
    for (auto& num : nums) {
      if (!count) {
        candicate = num;
      }
      if (candicate == num) {
        count++;
      } else {
        count--;
      }
    }
    count = 0;
    for (auto num : nums) {
      if (candicate == num) {
        count++;
      }
    }
    if (count > nums.size() / 2) {
      return candicate;
    }
    return -1;
  }
};

int main() {
  Solution s;
  cout << s.majorityElement({3, 2}) << endl;
  system("pause");
  return 0;
}
