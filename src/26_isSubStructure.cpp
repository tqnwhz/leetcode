#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  bool continousSubStructure(TreeNode* A, TreeNode* B) {
    if (B == NULL) {
      return true;
    }
    if (A == NULL) {
      return false;
    }
    return B->val == A->val && continousSubStructure(A->left, B->left) &&
           continousSubStructure(A->right, B->right);
  }

  bool isSubStructure(TreeNode* A, TreeNode* B) {
    if (B == NULL || A == NULL) {
      return false;
    }
    if (continousSubStructure(A, B)) {
      return true;
    }
    return isSubStructure(A->left, B) || isSubStructure(A->right, B);
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
