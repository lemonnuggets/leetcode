#include "../modules/index.h"
#define ITERATIONS 1
static auto _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class BinarySearchTree {
 private:
  TreeNode* root = nullptr;
  void static insert(TreeNode* node, int x) {
    if (x < node->val) {
      if (node->left == nullptr) {
        node->left = new TreeNode(x);
        return;
      }
      return insert(node->left, x);
    }

    if (node->right == nullptr) {
      node->right = new TreeNode(x);
      return;
    }
    return insert(node->right, x);
  }

 public:
  BinarySearchTree() { this->root = new TreeNode(); }
  BinarySearchTree(int x) { this->root = new TreeNode(x); }
  BinarySearchTree(vector<int>& x) { this->insertAll(x); }
  void insert(int x) {
    if (this->root == nullptr) {
      this->root = new TreeNode(x);
      return;
    }
    this->insert(root, x);
  }
  void insertAll(vector<int>& x) {
    int n = x.size();
    for (int i = 0; i < n; i++) {
      this->insert(x[i]);
    }
  }
  void print() {
    Output::treePrint(root);
    cout << endl;
  }
};
class Solution {
 private:
  struct VectorHasher {
    int operator()(const vector<int>& V) const {
      unsigned int hash = V.size();
      for (auto& i : V) {
        hash ^= i + 0x9e3779b9 + (hash << 6) + (hash >> 2);
      }
      return hash;
    }
  };
  vector<long long> factorials;
  unordered_map<vector<int>, int, VectorHasher> hashMap;
  static int mod(long long x) {
    int m = 1e9 + 7;
    if (x > 0) return x % m;
    return m + (x % m);
  }

 public:
  Solution() { factorials = {1}; }
  long long factorial(int x) {
    if (x < 0) {
      throw invalid_argument("Factorial of negative number isn't defined");
    }
    int n = factorials.size();
    if (x < n) {
      return factorials[x];
    }
    factorials.emplace_back(x * factorial(x - 1));
    // Output::vectorPrint(factorials);
    // cout << endl;
    return factorials[x];
  }
  int comb_C(int n, int r) {
    // Causes problems due to large values involved
    // in the calculation. We also cannot take a
    // modulo of the denominator directly. Instead
    // what can be done is, using pascal triangle
    // to find nCr or using inverse modulo to simplify
    auto denominator = factorial(min(r, n - r));
    long long numerator = 1;
    int x = max(r, n - r);
    for (int i = x + 1; i <= n; i++) {
      numerator = i * numerator;
    }
    return mod(numerator / denominator);
  }
  int numOfWaysTotal(vector<int>& nums) {
    if (nums.size() <= 2) {
      return 1;
    }
    if (hashMap.find(nums) != hashMap.end()) {
      return hashMap[nums];
    }
    int root = nums[0];
    vector<int> leftElements, rightElements;
    copy_if(nums.begin(), nums.end(), back_inserter(leftElements),
            [root](int i) { return i < root; });
    copy_if(nums.begin(), nums.end(), back_inserter(rightElements),
            [root](int i) { return i > root; });
    transform(rightElements.begin(), rightElements.end(), rightElements.begin(),
              [root](int i) { return i - root; });
    int n = leftElements.size();
    int m = rightElements.size();
    int leftWays = numOfWaysTotal(leftElements);
    int rightWays = numOfWaysTotal(rightElements);
    int possibleArrangements = comb_C(n + m, n);
    hashMap[nums] =
        mod((long)leftWays * mod((long)rightWays * possibleArrangements));
    return hashMap[nums];
  }
  int numOfWays(vector<int>& nums) { return numOfWaysTotal(nums) - 1; }
};
class Optimal {
 public:
  int numOfWays(vector<int>& nums) {
    long long mod = 1e9 + 7;
    int n = nums.size();

    // Pascal triangle
    table.resize(n + 1);
    for (int i = 0; i < n + 1; ++i) {
      table[i] = vector<long long>(i + 1, 1);
      for (int j = 1; j < i; ++j) {
        table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
      }
    }

    long long ans = dfs(nums, mod);
    return ans % mod - 1;
  }

 private:
  vector<vector<long long>> table;
  long long dfs(vector<int>& nums, long long mod) {
    int n = nums.size();
    if (n <= 2) return 1;

    // find left sub-sequence elements and right sub-sequence elements
    vector<int> left, right;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] < nums[0])
        left.push_back(nums[i]);
      else
        right.push_back(nums[i]);
    }

    // recursion with left subtree and right subtree
    long long left_res = dfs(left, mod) % mod;
    long long right_res = dfs(right, mod) % mod;

    // look up table and multiple them together
    int left_len = left.size(), right_len = right.size();
    return (((table[n - 1][left_len] * left_res) % mod) * right_res) % mod;
  }
};
int test(vector<int>& nums) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nnums (size = " << nums.size() << ") = \t";
  Output::vectorPrint(nums);
  cout << endl;
  BinarySearchTree* bst = new BinarySearchTree(nums);
  bst->print();

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::numOfWays, s, nums);
  cout << "\tNumber of Ways (mine), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::numOfWays, o, nums);
  cout << "\tNumber of Ways (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  vector<int> x = {3, 1, 2, 5, 4, 6};
  test(x);
  x = {2, 1, 3};
  test(x);
  x = {3, 4, 5, 1, 2};
  test(x);
  x = {2, 1, 3, 4};
  test(x);
  x = {1, 2, 3};
  test(x);
  x = {9, 4, 2, 1, 3, 6, 5, 7, 8, 14, 11, 10, 12, 13, 16, 15, 17, 18};
  test(x);
  x = {31, 23, 14, 24, 15, 12, 25, 28, 5,  35, 17, 6,  9,  11, 1,  27, 18, 20,
       2,  3,  33, 10, 13, 4,  7,  36, 32, 29, 8,  30, 26, 19, 34, 22, 21, 16};
  test(x);
  x = {30, 11, 46, 3,  29, 22, 37, 32, 13, 49, 48, 16, 40, 8,  24, 44, 9,
       39, 25, 21, 41, 26, 43, 19, 47, 7,  10, 31, 45, 4,  35, 14, 20, 23,
       15, 17, 38, 2,  6,  18, 5,  33, 27, 36, 42, 28, 12, 34, 1};
  test(x);
  return 0;
}