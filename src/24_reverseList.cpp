#include <bits/stdc++.h>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode* end = NULL;
    while (head != NULL) {
      auto t = head->next;
      head->next = end;
      end = head;
      head = t;
    }
    return end;
  }
};

class Solution1 {
 public:
  pair<ListNode*, ListNode*> recReverse(ListNode* head) {
    if (head == NULL || head->next == NULL) {
      return {head, head};
    }
    auto [new_head, tail] = recReverse(head->next);
    tail->next = head;
    head->next = NULL;
    return {new_head, head};
  }

  ListNode* reverseList(ListNode* head) { return recReverse(head).first; }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
