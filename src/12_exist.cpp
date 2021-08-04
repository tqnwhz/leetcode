#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  bool dfs(vector<vector<char>>& board, string word, int idx, int x, int y,
           vector<vector<bool>>& visited) {
    if (idx >= word.size()) {
      return true;
    }
    if (visited[x][y] || board[x][y] != word[idx]) {
      return false;
    }
    if (idx + 1 >= word.size()) {
      return true;
    }
    visited[x][y] = true;
    if (x > 0 && dfs(board, word, idx + 1, x - 1, y, visited)) {
      return true;
    }
    if (y > 0 && dfs(board, word, idx + 1, x, y - 1, visited)) {
      return true;
    }
    if (x < board.size() - 1 && dfs(board, word, idx + 1, x + 1, y, visited)) {
      return true;
    }
    if (y < board[0].size() - 1 &&
        dfs(board, word, idx + 1, x, y + 1, visited)) {
      return true;
    }
    visited[x][y] = false;
    return false;
  }

  bool exist(vector<vector<char>>& board, string word) {
    vector<vector<bool>> visited(board.size(),
                                 vector<bool>(board[0].size(), false));
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[0].size(); j++) {
        if (dfs(board, word, 0, i, j, visited)) return true;
      }
    }
    return false;
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
