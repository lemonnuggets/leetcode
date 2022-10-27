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
  template <typename T>
  static void vector(vector<T> a) {
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
  static void tree(TreeNode* root) { treePrinter(root, nullptr, false); }
};
