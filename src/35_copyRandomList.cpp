#include <bits/stdc++.h>

using namespace std;

class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> pMap;
    if (head == NULL) {
      return head;
    }
    for (auto p = head; p != NULL; p = p->next) {
      pMap[p] = new Node(p->val);
    }
    auto new_head = pMap[head];

    for (auto p = new_head, q = head; q != NULL; p = p->next, q = q->next) {
      p->random = pMap[q->random];
      p->next = pMap[q->next];
    }
    return new_head;
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
