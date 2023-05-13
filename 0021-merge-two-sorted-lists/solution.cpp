#include "../modules/index.h"
#define ITERATIONS 2
class Solution {
 public:
  ListNode* copy(ListNode* l) {
    ListNode* newHead = new ListNode(l->val);
    ListNode* curr = newHead;
    ListNode* currL = l;
    while (currL->next != nullptr) {
      curr->next = new ListNode(currL->next->val);
      curr = curr->next;
      currL = currL->next;
    }
    return newHead;
  }
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // if used without copy(), l1 and l2 will be modified
    // leading to an infinite loop if function is called
    // again with same l1 and l2.
    ListNode *list1 = copy(l1), *list2 = copy(l2);
    ListNode* newHead = nullptr;
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
int test(vector<int>& x, vector<int>& y) {
  Solution s = Solution();

  ListNode* x_list = new ListNode(x);
  ListNode* y_list = new ListNode(y);

  cout << "\nX = ";
  Output::listPrint(x_list);
  cout << endl;
  cout << "Y = ";
  Output::listPrint(y_list);
  cout << endl;

  auto result = measureMethodPerformance(ITERATIONS, &Solution::mergeTwoLists,
                                         s, x_list, y_list);

  cout << "\tTime Taken: " << result.first << "\t\tMerged List = \t";
  Output::listPrint(result.second);
  cout << endl;

  return 0;
}
int main() {
  vector<int> nums1, nums2;

  nums1 = {1, 2, 3};
  nums2 = {2, 5, 6};
  test(nums1, nums2);

  nums1 = {1};
  nums2 = {};
  test(nums1, nums2);

  return 0;
}