#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  bool dfs(TreeNode *l, TreeNode *r) {
    if (l == NULL && r != NULL || l != NULL && r == NULL) {
      return false;
    }
    if (l == NULL && r == NULL) {
      return true;
    }
    return l->val == r->val && dfs(l->left, r->right) && dfs(l->right, r->left);
  }

  bool isSymmetric(TreeNode *root) {
    if (root == NULL) {
      return true;
    }

    return dfs(root->left, root->right);
  }
};
int main() {
  Solution s;

  system("pause");
  return 0;
}
