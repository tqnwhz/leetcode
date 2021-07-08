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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    auto start = head;
    auto now = head;
    if (now == NULL) {
      return NULL;
    }
    for (int i = 0; i < n; i++) {
      now = now->next;
    }
    // 如果now
    if (now == NULL) {
      return head->next;
    }
    while (now->next != NULL) {
      now = now->next;
      start = start->next;
    }
    start->next = start->next->next;
    return head;
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
