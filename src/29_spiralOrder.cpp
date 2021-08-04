#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  //[left,right) //[top,bottom)

  vector<int> result;

  void recSpiralOrder(vector<vector<int>>& matrix, int left, int right, int top,
                      int bottom) {
    if (top >= bottom || left >= right) {
      return;
    }
    result.insert(result.end(), matrix[top].begin() + left,
                  matrix[top].begin() + right);
    if (top + 1 >= bottom) {
      return;
    }
    for (int i = top + 1, j = right - 1; i < bottom; i++) {
      result.push_back(matrix[i][j]);
    }
    for (int i = bottom - 1, j = right - 2; j >= left; j--) {
      result.push_back(matrix[i][j]);
    }
    if (left < right - 1) {
      for (int i = bottom - 2, j = left; i >= top + 1; i--) {
        result.push_back(matrix[i][j]);
      }
    }
    recSpiralOrder(matrix, left + 1, right - 1, top + 1, bottom - 1);
  }

  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    if (matrix.empty()) {
      return {};
    }
    result.clear();
    recSpiralOrder(matrix, 0, matrix[0].size(), 0, matrix.size());
    return result;
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
