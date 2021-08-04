#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  pair<ListNode*, ListNode*> reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL) {
      return {head, head};
    }
    auto [new_head, tail] = reverseList(head->next);
    tail->next = head;
    head->next = NULL;
    return {new_head, head};
  }

  ListNode* reverseKGroup(ListNode* head, int k) {
    auto dummyHead = new ListNode(-1);
    dummyHead->next = head;
    auto prev = dummyHead;
    // [p,q]
    for (auto p = head; p != NULL;) {
      auto q = p;
      int i = 0;
      for (; i < k - 1 && q->next != NULL; i++) {
        q = q->next;
      }
      if (i < k - 1) {
        break;
      }
      auto rest = q->next;
      q->next = NULL;
      auto [new_head, tail] = reverseList(p);
      tail->next = rest;
      prev->next = new_head;
      prev = tail;
      p = tail->next;
    }
    return dummyHead->next;
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
