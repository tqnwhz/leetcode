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
  void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
    if (root == NULL) {
      return;
    }
    parent[root->left] = root;
    parent[root->right] = root;
    dfs(root->left, parent);
    dfs(root->right, parent);
  }

  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent;
    set<pair<TreeNode*, TreeNode*>> visited;
    dfs(root, parent);
    list<TreeNode*> que{target};
    for (int i = 0; i < k; i++) {
      auto curSize = que.size();
      for (int j = 0; j < curSize; j++) {
        auto now = que.front();
        que.pop_front();
        if (now == NULL) {
          continue;
        }
        auto neibors = vector<TreeNode*>{now->left, now->right, parent[now]};
        for (auto neibor : neibors) {
          if (neibor != NULL && !visited.count({neibor, now})) {
            que.push_back(neibor);
            visited.insert({now, neibor});
          }
        }
      }
    }
    vector<int> result;
    for (auto v : que) {
      result.push_back(v->val);
    }
    return result;
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
