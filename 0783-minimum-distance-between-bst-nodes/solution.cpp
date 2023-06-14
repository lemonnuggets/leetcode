#include "../modules/index.h"
#define ITERATIONS 50
static auto _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class Solution {
  int currentMin;
  int comparingWith;

  // inorder traversal of binary search tree leads to ascending order.
  // therefore just getting difference with last processed node gives
  // minimum absolute difference.
  // (minimum absolute difference will always be between two adjacent
  // elements in a sorted list)
 public:
  void helper(TreeNode* root) {
    if (root == nullptr) {
      return;
    }
    helper(root->left);
    if (comparingWith != -1) {
      currentMin = min(currentMin, abs(root->val - comparingWith));
    }
    comparingWith = root->val;
    helper(root->right);
  }
  int minDiffInBST(TreeNode* root) {
    currentMin = INT_MAX;
    comparingWith = -1;
    helper(root);
    return currentMin;
  }
};
class Optimal {
 private:
  int res;
  int pre;

 public:
  void helper(TreeNode* root) {
    if (!root) return;

    helper(root->left);
    if (pre != -1) res = min(res, abs(root->val - pre));
    pre = root->val;
    helper(root->right);
  }
  int minDiffInBST(TreeNode* root) {
    res = INT_MAX;
    pre = -1;
    helper(root);

    return res;
  }
};
int test(vector<int>& x) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  TreeNode* root;
  if (x.size() > 0)
    root = new TreeNode(x);
  else
    root = nullptr;

  cout << "\nTree from x, root = \n";
  Output::treePrint(root);
  cout << endl;
  // cout << root << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::minDiffInBST, s, root);
  cout << "\nGet Minimum Difference (mine), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result =
      measureMethodPerformance(ITERATIONS, &Optimal::minDiffInBST, o, root);
  cout << "\nGet Minimum Difference (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  vector<int> x = {4, 2, 6, 1, 3};
  test(x);
  x = {1, 0, 48, INVALID_VALUE, INVALID_VALUE, 12, 49};
  test(x);
  x = {236, 104, 701, INVALID_VALUE, 227, INVALID_VALUE, 911};
  test(x);
  return 0;
}