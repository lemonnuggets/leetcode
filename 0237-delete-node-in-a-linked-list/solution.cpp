#include "../modules/index.h"
class Solution {
 public:
  void deleteNode(ListNode* node) {
    // ListNode* parent;
    // while (node->next != nullptr) {
    //   node->val = node->next->val;
    //   parent = node;
    //   node = node->next;
    // }
    // parent->next = nullptr;
    node->val = node->next->val;
    node->next = node->next->next;
  }
};

int test(ListNode* headNode, ListNode* testNode) {
  Solution s = Solution();
  Timer t = Timer();
  int duration;

  cout << "\nList = ";
  Output::listPrint(headNode);
  cout << endl;
  cout << "From Test Node = ";
  Output::listPrint(testNode);
  cout << endl;

  t.startClock();
  s.deleteNode(testNode);
  duration = t.stopClock();

  cout << "Delete Node, X = \t";
  Output::listPrint(headNode);
  cout << "\t\t\t\tTime Taken: " << duration << endl;
  return 0;
}
int main() {
  vector<int> x = {4, 5, 1, 9};
  ListNode* head = new ListNode(x);
  test(head, head->next);

  x = {4, 5, 1, 9};
  head = new ListNode(x);
  test(head, head->next->next);

  x = {4, 5, 1, 9, 8, 2, 1};
  head = new ListNode(x);
  test(head, head->next->next);
}