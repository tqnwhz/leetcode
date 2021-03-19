#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  vector<int> reversePrint(ListNode* head) {
    vector<int> s;
    while (head != NULL) {
      s.push_back(head->val);
      head = head->next;
    }
    reverse(s.begin(), s.end());
    return s;
  }
};
int main() {
  system("pause");
  return 0;
}
