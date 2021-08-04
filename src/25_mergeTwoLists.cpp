#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    auto head = new ListNode(0);
    auto p = head;
    while (l1 != NULL || l2 != NULL) {
      if (l1 == NULL) {
        p->next = l2;
        break;
      } else if (l2 == NULL) {
        p->next = l1;
        break;
      } else {
        if (l1->val < l2->val) {
          p->next = l1;
          p = p->next;
          l1 = l1->next;
        } else {
          p->next = l2;
          p = p->next;
          l2 = l2->next;
        }
      }
    }
    return head->next;
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
