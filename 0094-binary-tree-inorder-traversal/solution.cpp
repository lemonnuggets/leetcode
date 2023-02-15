#include "../modules/index.h"
class Solution {
 public:
  vector<int> inorderTraversalRecursive(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) {
      result = {};
    } else {
      result = inorderTraversalRecursive(root->left);
      result.push_back(root->val);
      vector<int> rightResult = inorderTraversalRecursive(root->right);
      result.insert(result.end(), rightResult.begin(), rightResult.end());
    }
    return result;
  }
  vector<int> inorderTraversalIterative(TreeNode* root) {
    vector<int> nodes;
    stack<TreeNode*> todo;
    while (root || !todo.empty()) {
      while (root) {
        todo.push(root);
        root = root->left;
      }
      root = todo.top();
      todo.pop();
      nodes.push_back(root->val);
      root = root->right;
    }
    return nodes;
  }
  vector<int> inorderTraversal(TreeNode* root) {
    return inorderTraversalRecursive(root);
  }
};

int test(vector<int>& x) {
  Solution s = Solution();
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

  vector<int> result;
  t.startClock();
  result = s.inorderTraversalRecursive(root);
  duration = t.stopClock();

  cout << "\tInorder Traversal (recursive), result = \t";
  Output::vectorPrint(result);
  cout << "\t\t\t\tTime Taken: " << duration << endl;

  t.startClock();
  result = s.inorderTraversalIterative(root);
  duration = t.stopClock();

  cout << "\tInorder Traversal (iterative), result = \t";
  Output::vectorPrint(result);
  cout << "\t\t\t\tTime Taken: " << duration << endl;
  return 0;
}
int main() {
  vector<int> x;
  x = {1, INVALID_VALUE, 2, 3};
  test(x);
  x = {};
  test(x);
  x = {1};
  test(x);
  x = {1, 2, 3, 4, 5, 6, 7, 8, 9, INVALID_VALUE, 10, 11, INVALID_VALUE, 12, 13};
  test(x);
  return 0;
}
