#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  vector<int> exchange(vector<int>& nums) {
    int p = 0;
    for (auto& num : nums) {
      if (num % 2 == 1) {
        swap(num, nums[p++]);
      }
    }
    return nums;
  }
};
int main() {
  Solution s;

  system("pause");
  return 0;
}
