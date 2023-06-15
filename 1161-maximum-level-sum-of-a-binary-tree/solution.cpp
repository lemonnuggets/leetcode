#include "../modules/index.h"
#define ITERATIONS 1
static auto _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class Solution {
 public:
  int maxLevelSum(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int maxSumLevel = 0;
    int maxSum = INT_MIN;
    int currLevel = 1;
    int currSum = 0;
    int nodesInCurrLevel = 1;
    int nodesInNextLevel = 0;
    while (nodesInCurrLevel + nodesInNextLevel > 0) {
      TreeNode* curr = q.front();
      q.pop();
      nodesInCurrLevel--;

      currSum += curr->val;
      if (curr->left != nullptr) {
        q.push(curr->left);
        nodesInNextLevel++;
      }
      if (curr->right != nullptr) {
        q.push(curr->right);
        nodesInNextLevel++;
      }

      if (nodesInCurrLevel <= 0) {
        if (currSum > maxSum) {
          maxSumLevel = currLevel;
          maxSum = currSum;
        }
        currLevel++;
        currSum = 0;
        nodesInCurrLevel = nodesInNextLevel;
        nodesInNextLevel = 0;
      }
    }
    return maxSumLevel;
  }
};
class Optimal {
 public:
  int maxLevelSum(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    int maxi = INT_MIN, lvl = 0, res = 0;

    while (!q.empty()) {
      lvl++;
      int size = q.size();
      int sum = 0;
      // instead of keeping track of number of nodes in current and next level
      // here it clears all elements in a single level using a for loop.
      for (int i = 0; i < size; i++) {
        auto node = q.front();
        q.pop();
        sum += node->val;

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }

      if (sum > maxi) {
        res = lvl;
        maxi = sum;
      }
    }

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
      measureMethodPerformance(ITERATIONS, &Solution::maxLevelSum, s, root);
  cout << "\nMax Level Sum (mine), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::maxLevelSum, o, root);
  cout << "\nMax Level Sum (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  vector<int> x = {1, 7, 0, 7, -8, INVALID_VALUE, INVALID_VALUE};
  test(x);
  x = {989,           INVALID_VALUE, 10250,         98693, -89388,
       INVALID_VALUE, INVALID_VALUE, INVALID_VALUE, -32127};
  test(x);
  x = {989, 0, 10250, 98693, -89388, 0, 0, 0, -32127};
  //         .——— 0
  //     .——— 10250
  //    |    `——— 0
  // ——— 989
  //    |    .——— -89388
  //     `——— 0
  //        |    .——— -32127
  //         `——— 98693
  //             `——— 0
  test(x);
  return 0;
}