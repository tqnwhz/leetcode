#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* deleteNode(ListNode* head, int val) {
    auto p = head;
    if (p->val == val) {
      return p->next;
    }
    while (p->next != NULL) {
      if (p->next->val == val) {
        p->next = p->next->next;
        break;
      }
      p = p->next;
    }
    return head;
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
