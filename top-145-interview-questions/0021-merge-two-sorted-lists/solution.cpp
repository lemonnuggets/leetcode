#include "../../modules/index.h"
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
int test(vector<int>& x, vector<int>& y) {
  Solution s = Solution();
  Timer t = Timer();
  int duration;

  ListNode* x_list = new ListNode(x);
  ListNode* y_list = new ListNode(y);

  cout << "\nX = ";
  Output::listPrint(x_list);
  cout << endl;
  cout << "Y = ";
  Output::listPrint(y_list);
  cout << endl;

  t.startClock();
  ListNode* merged_list = s.mergeTwoLists(x_list, y_list);
  duration = t.stopClock();

  cout << "\tTime Taken: " << duration << "\t\tMerged List = \t";
  Output::listPrint(merged_list);
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