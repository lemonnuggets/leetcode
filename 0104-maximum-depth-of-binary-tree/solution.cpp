
#include "../modules/index.h"
#define ITERATIONS 50
class Solution {
 public:
  int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};

int test(vector<int>& x) {
  Solution s = Solution();

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

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::maxDepth, s, root);
  cout << "\tMaxDepth (recursive), result = " << result.second;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
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
