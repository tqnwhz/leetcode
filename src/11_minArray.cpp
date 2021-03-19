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
  int minArray(vector<int>& numbers) {
    return numbers[binSearch(numbers, 0, numbers.size() - 1)];
  }

  int binSearch(vector<int>& numbers, int left, int right) {
    int mid;
    while (left <= right) {
      mid = left + (right - left) / 2;
      if (numbers[mid] > numbers[right])
        left = mid + 1;
      else if (numbers[mid] < numbers[right])
        right = mid;
      else
        right = right - 1;
    }
    return mid;
  }
};
int main() {
  Solution s;

  system("pause");
  return 0;
}
