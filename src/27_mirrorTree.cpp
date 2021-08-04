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
  TreeNode* mirrorTree(TreeNode* root) {
    if (root == NULL) {
      return root;
    }
    auto r = root->right;
    root->right = mirrorTree(root->left);
    root->left = mirrorTree(r);
    return root;
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
