#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* getKthFromEnd(ListNode* head, int k) {
    auto p = head;
    for (int i = 0; i < k - 1; i++) {
      p = p->next;
    }
    while (p->next != NULL) {
      p = p->next;
      head = head->next;
    }
    return head;
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
