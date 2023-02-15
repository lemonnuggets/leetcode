#include "constants.h"
#include "imports.h"
class TreeNode {
 private:
  static TreeNode* insertLevelOrder(vector<int> ra, int i) {
    if (ra[i] != INVALID_VALUE && i < ra.size())
      return new TreeNode(ra[i], insertLevelOrder(ra, 2 * i + 1),
                          insertLevelOrder(ra, 2 * i + 2));
    return nullptr;
  }

 public:
  int val;
  TreeNode* left;
  TreeNode* right;
  void assign(int val = 0, TreeNode* left = nullptr,
              TreeNode* right = nullptr) {
    this->val = val;
    this->left = left;
    this->right = right;
  }
  void assign(TreeNode* root) {
    this->assign(root->val, root->left, root->right);
  }

  TreeNode() { this->assign(); }
  TreeNode(int x) { this->assign(x); }
  TreeNode(int x, TreeNode* left, TreeNode* right) {
    this->assign(x, left, right);
  }
  TreeNode(vector<int> x) {
    TreeNode* tree = this->insertLevelOrder(x, 0);
    this->assign(tree);
  }
};
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
  ListNode(vector<int>& x) { this->assign(x); }
  void append(int x) {
    ListNode* new_node = new ListNode(x);
    ListNode* curr = this->next;
    while (curr != nullptr && curr->next != nullptr) curr = curr->next;
    curr->next = new_node;
  }
  void assign(vector<int>& x) {
    if (x.size() <= 0) return;
    this->val = x[0];
    this->next = nullptr;
    ListNode* end = this;
    for (int i = 1; i < x.size(); i++) {
      ListNode* new_end = new ListNode(x[i]);
      end->next = new_end;
      end = end->next;
    }
    return;
  }
};