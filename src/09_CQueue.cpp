#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class CQueue {
 public:
  stack<int> mainStack;
  stack<int> tmpStack;

  CQueue() {}

  void appendTail(int value) { mainStack.push(value); }

  int deleteHead() {
    if (mainStack.empty()) return -1;
    while (!mainStack.empty()) {
      tmpStack.push(mainStack.top());
      mainStack.pop();
    }
    int head = tmpStack.top();
    tmpStack.pop();
    while (!tmpStack.empty()) {
      mainStack.push(tmpStack.top());
      tmpStack.pop();
    }
    return head;
  }
};

class Solution {};
int main() {
  Solution s;

  system("pause");
  return 0;
}
