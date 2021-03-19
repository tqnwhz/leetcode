
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  double findKLeastNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    if (nums1.empty()) {
      return nums2[k - 1];
    }
    if (nums2.empty()) {
      return nums1[k - 1];
    }
    if (k == 1) {
      return min(nums1[0], nums2[0]);
    }
    int idx1 = min(k / 2 - 1, (int)nums1.size() - 1);
    int idx2 = min(k / 2 - 1, (int)nums2.size() - 1);
    if (nums1[idx1] <= nums2[idx2]) {
      auto newNums1 = vector<int>(nums1.begin() + idx1 + 1, nums1.end());
      return findKLeastNumber(newNums1, nums2, k - idx1 - 1);
    } else {
      auto newNums2 = vector<int>(nums2.begin() + idx2 + 1, nums2.end());
      return findKLeastNumber(nums1, newNums2, k - idx2 - 1);
    }
  }

  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size() + nums2.size();
    if (n % 2 == 0) {
      return (findKLeastNumber(nums1, nums2, n / 2) +
              findKLeastNumber(nums1, nums2, n / 2 + 1)) /
             2.0;
    }
    return findKLeastNumber(nums1, nums2, n / 2 + 1);
  }
};
int main() {
  Solution s;
  vector<int> nums1 = {1, 2}, nums2 = {3};
  cout << s.findMedianSortedArrays(nums1, nums2) << endl;
  system("pause");
  return 0;
}
