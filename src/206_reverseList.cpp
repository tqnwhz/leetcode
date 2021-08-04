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
  ListNode* reverseList(ListNode* head) {
    ListNode* end = NULL;
    while (head != NULL) {
      auto tmp = head->next;
      head->next = end;
      end = head;
      head = tmp;
    }
    return end;
  }

  pair<ListNode*, ListNode*> recReverse(ListNode* head) {
    if (head == NULL || head->next == NULL) return {head, head};
    auto [new_head, tail] = recReverse(head->next);
    tail->next = head;
    head->next = NULL;
    return {new_head, head};
  }

  ListNode* reverseList1(ListNode* head) { return recReverse(head).first; }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
