#include <bits/stdc++.h>
using namespace std;
class ListNode {
 public:
  int val;
  ListNode* next;
  ListNode() {
    this->val = 0;
    this->next = nullptr;
  }
  ListNode(int x) {
    this->val = x;
    this->next = nullptr;
  }
  ListNode(int x, ListNode* next) {
    this->val = x;
    this->next = next;
  }
};

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;
    ListNode* newHead;
    if (list1->val < list2->val) {
      newHead = list1;
      list1 = list1->next;
    } else {
      newHead = list2;
      list2 = list2->next;
    }
    ListNode* curr = newHead;
    while (!(list1 == nullptr && list2 == nullptr)) {
      if (list1 == nullptr || (list2 != nullptr && list2->val < list1->val)) {
        curr->next = list2;
        list2 = list2->next;
      } else {
        curr->next = list1;
        list1 = list1->next;
      }
      curr = curr->next;
    }
    return newHead;
  }
};
int main() {
  Solution s = Solution();
  return 0;
}