#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  int numSubarraysWithSum(vector<int>& nums, int goal) {
    vector<int> oneIndexes;
    int i = 0;
    for (auto v : nums) {
      if (v == 1) {
        oneIndexes.push_back(i);
      }
      i++;
    }
    int res = 0;
    if (goal == 0) {
      for (int i = 0; i < oneIndexes.size(); i++) {
        int idx = oneIndexes[i];
        int start = oneIndexes[i];
        if (i != 0) {
          start = oneIndexes[i] - oneIndexes[i - 1] - 1;
        }
        res += start * (start - 1) / 2 + start;
      }
      int end = oneIndexes.empty()
                    ? nums.size()
                    : nums.size() - oneIndexes[oneIndexes.size() - 1] - 1;
      res += end * (end - 1) / 2 + end;
      return res;
    }
    for (int i = 0; i < oneIndexes.size() - goal + 1; i++) {
      int idx = oneIndexes[i];
      int endIdx = i + goal - 1;
      int end;
      int start;
      if (i != 0) {
        start = oneIndexes[i] - oneIndexes[i - 1] - 1;
      } else {
        start = oneIndexes[i];
      }
      if (endIdx != oneIndexes.size() - 1) {
        end = oneIndexes[endIdx + 1] - oneIndexes[endIdx] - 1;
      } else {
        end = nums.size() - oneIndexes[endIdx] - 1;
      }
      res += (start + 1) * (end + 1);
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> arr = {1, 0, 1, 0, 1};
  cout << s.numSubarraysWithSum(arr, 2) << endl;
  system("pause");
  return 0;
}
