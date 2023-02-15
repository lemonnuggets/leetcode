#include "imports.h"
#include "structures.h"
class Output {
 private:
  class Trunk {
   public:
    Trunk* prev;
    string str;
    Trunk(Trunk* prev, string str) {
      this->prev = prev;
      this->str = str;
    }
    void showTrunks() {
      if (this->prev != nullptr) this->prev->showTrunks();
      cout << this->str;
    }
  };
  static void treePrinter(TreeNode* root, Trunk* prev, bool isLeft) {
    if (root == nullptr) return;

    string prev_str = "    ";
    Trunk* trunk = new Trunk(prev, prev_str);

    treePrinter(root->right, trunk, true);

    if (!prev) {
      trunk->str = "———";
    } else if (isLeft) {
      trunk->str = ".———";
      prev_str = "   |";
    } else {
      trunk->str = "`———";
      prev->str = prev_str;
    }

    trunk->showTrunks();
    cout << " " << root->val << endl;

    if (prev) {
      prev->str = prev_str;
    }
    trunk->str = "   |";

    treePrinter(root->left, trunk, false);
  }

 public:
  template <typename PrinitableType>
  static void pairPrint(pair<PrinitableType, PrinitableType> a) {
    cout << "<" << a.first << ", " << a.second << ">";
  }
  template <typename PrinitableType, typename TypeX>
  static void pairPrint(pair<TypeX, TypeX> a,
                        function<PrinitableType(TypeX)> getVal) {
    cout << "<" << getVal(a.first) << ", " << getVal(a.second) << ">";
  }
  template <typename PrinitableType, typename TypeX>
  static void pairPrint(pair<TypeX, TypeX> a,
                        function<PrinitableType(TypeX)> getVal,
                        function<bool(TypeX)> canGetVal) {
    cout << "<";
    if (canGetVal(a.first))
      cout << getVal(a.first);
    else
      cout << "_";
    cout << ", ";
    if (canGetVal(a.second))
      cout << getVal(a.second);
    else
      cout << "_";
    cout << ">";
  }
  template <typename PrintableType>
  static void vectorPrint(vector<PrintableType> a) {
    cout << "[";
    for (auto it = a.begin(); it != a.end(); it++) {
      if (it == a.end() - 1) {
        cout << *it;
      } else {
        cout << *it << ", ";
      }
    }
    cout << "]";
  }
  static void treePrint(TreeNode* root) { treePrinter(root, nullptr, false); }
  static void listPrint(ListNode* a) {
    string seperator = " -> ";
    ListNode* curr = a;
    while (curr->next != nullptr) {
      cout << curr->val << seperator;
      curr = curr->next;
    }
    cout << curr->val;
  }
};
