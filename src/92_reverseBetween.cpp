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

  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (left == right) {
      return head;
    }
    auto dummyHead = new ListNode(-1);
    dummyHead->next = head;
    auto lp = dummyHead, rp = dummyHead;
    for (int i = 0; i < left - 1; i++) lp = lp->next;
    for (int i = 0; i < right; i++) rp = rp->next;
    auto rest = rp->next;
    rp->next = NULL;
    auto [new_head, tail] = reverseList(lp->next);
    lp->next = new_head;
    tail->next = rest;
    return dummyHead->next;
  }
};

int main() {
  Solution s;

  system("pause");
  return 0;
}
