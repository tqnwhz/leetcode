#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.empty()) {
      return NULL;
    }
    auto root = new TreeNode(preorder[0]);
    auto index =
        find(inorder.begin(), inorder.end(), root->val) - inorder.begin();
    auto leftPreorder =
        vector<int>(preorder.begin() + 1, preorder.begin() + 1 + index);
    auto leftInorder = vector<int>(inorder.begin(), inorder.begin() + index);
    root->left = buildTree(leftPreorder, leftInorder);
    auto rightPreorder =
        vector<int>(preorder.begin() + 1 + index, preorder.end());
    auto rightInorder = vector<int>(inorder.begin() + 1 + index, inorder.end());
    root->right = buildTree(rightPreorder, rightInorder);
    return root;
  }
};
int main() {
  system("pause");
  return 0;
}
