#include "../modules/index.h"
// auto getVal = [](TreeNode* T) { return T->val; };
// auto canGetVal = [](TreeNode* T) { return T != nullptr; };
// void logPair(string action, pair<TreeNode*, TreeNode*> P) {
//   cout << action << " ";
//   Output::pairPrint<int, TreeNode*>(P, getVal, canGetVal);
//   cout << endl;
// }

class Solution {
 public:
  class Iterative {
   public:
    static bool areMirrorImages(TreeNode* left, TreeNode* right) {
      if (left == nullptr && right == nullptr) return true;
      if (left == nullptr || right == nullptr) return false;
      stack<pair<TreeNode*, TreeNode*>> pairsToCompare;
      pairsToCompare.push(make_pair(left, right));
      while (pairsToCompare.size() > 0) {
        auto comparisonPair = pairsToCompare.top();
        pairsToCompare.pop();

        if (comparisonPair.first == nullptr && comparisonPair.second == nullptr)
          continue;
        if (comparisonPair.first == nullptr || comparisonPair.second == nullptr)
          return false;
        if (comparisonPair.first->val != comparisonPair.second->val)
          return false;

        pairsToCompare.push(make_pair(comparisonPair.first->right,
                                      comparisonPair.second->left));
        pairsToCompare.push(make_pair(comparisonPair.first->left,
                                      comparisonPair.second->right));
      }
      return true;
    }
    static bool isSymmetric(TreeNode* root) {
      if (root == nullptr) return true;
      return Iterative::areMirrorImages(root->left, root->right);
    }
  };
  class Recursive {
   public:
    static bool areMirrorImages(TreeNode* left, TreeNode* right) {
      if (left == nullptr && right == nullptr) return true;
      if (left == nullptr || right == nullptr) return false;
      return left->val == right->val &&
             Recursive::areMirrorImages(left->left, right->right) &&
             Recursive::areMirrorImages(left->right, right->left);
    }
    static bool isSymmetric(TreeNode* root) {
      if (root == nullptr) return true;
      return Recursive::areMirrorImages(root->left, root->right);
    }
  };
  bool isSymmetric(TreeNode* root) { return Recursive::isSymmetric(root); }
};

int test(vector<int>& x) {
  Timer t = Timer();
  int duration;

  cout << "\nX (size = " << x.size() << ") = \t";
  Output::vectorPrint(x);
  cout << endl;
  TreeNode* root;
  if (x.size() > 0)
    root = new TreeNode(x);
  else
    root = nullptr;
  cout << "Tree from x, root = " << endl;
  Output::treePrint(root);

  bool result;

  t.startClock();
  result = Solution::Recursive::isSymmetric(root);
  duration = t.stopClock();

  cout << "\tisSymmetric (recursive), result = " << result;
  cout << "\t\t\t\tTime Taken: " << duration << endl;

  t.startClock();
  result = Solution::Iterative::isSymmetric(root);
  duration = t.stopClock();

  cout << "\tisSymmetric (iterative), result = " << result;
  cout << "\t\t\t\tTime Taken: " << duration << endl;
  return 0;
}
int main() {
  vector<int> x;
  x = {1, 2, 2, 3, 4, 4, 3};
  test(x);
  x = {1, 2, 2, INVALID_VALUE, 3, INVALID_VALUE, 3};
  test(x);
  x = {1};
  test(x);
  x = {1, 2, 3, 4, 5, 6, 7, 8, 9, INVALID_VALUE, 10, 11, INVALID_VALUE, 12, 13};
  test(x);
  x = {2, 3, 3, 4, 5, 5};
  test(x);
  return 0;
}
