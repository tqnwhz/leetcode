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
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
class Solution {
 public:
  int countNodes(TreeNode *root) {
    if (root == NULL) {
      return 0;
    }
    int lh = 0, rh = 0;
    auto p = root;
    while (p != NULL) {
      p = p->left;
      lh++;
    }
    p = root;
    while (p != NULL) {
      p = p->right;
      rh++;
    }
    if (lh == rh) {
      return pow(2, lh) - 1;
    }
    return countNodes(root->right) + 1 + countNodes(root->left);
  }
};
int main() {
  Solution s;

  system("pause");
  return 0;
}
