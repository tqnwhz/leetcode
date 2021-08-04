#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  static const int MOD = 1'000'000'007;

  int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
    vector<int> sort1(nums1);
    int n = nums1.size();
    sort(sort1.begin(), sort1.end());
    int maxGain = 0, sum = 0;
    for (int i = 0; i < n; i++) {
      int low =
          lower_bound(sort1.begin(), sort1.end(), nums2[i]) - sort1.begin();
      int diff = abs(nums1[i] - nums2[i]);
      sum = (sum + diff) % MOD;
      if (low < n) {
        maxGain = max(maxGain, diff - (sort1[low] - nums2[i]));
      }
      if (low > 0) {
        maxGain = max(maxGain, diff - (nums2[i] - sort1[low - 1]));
      }
    }
    return (sum + MOD - maxGain) % MOD;
  }
};

int main() {
  Solution s;
  vector<int> a1 = {2, 4, 6, 8, 10};
  vector<int> a2 = {2, 4, 6, 8, 10};
  cout << s.minAbsoluteSumDiff(a1, a2) << endl;
  system("pause");
  return 0;
}
