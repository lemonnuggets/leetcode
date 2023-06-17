#include "../modules/index.h"
#define ITERATIONS 50
static auto _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class Solution {
 public:
  int makeArrayIncreasing(vector<int>& arr1, int start,
                          priority_queue<int, vector<int>, greater<int>> minQ) {
    // only passes 18 / 21 test cases
    int n = arr1.size();
    if (start >= n) return 0;
    if (start == 0 || arr1[start] > arr1[start - 1]) {
      int operations = makeArrayIncreasing(arr1, start + 1, minQ);
      if (operations != -1) return operations;
    }
    if (minQ.empty()) {
      return -1;
    }

    int initialValue = arr1[start];
    int candidate;
    do {
      candidate = minQ.top();
      minQ.pop();
      if (start > 0) {
        while (!(candidate > arr1[start - 1])) {
          if (minQ.empty()) return -1;
          candidate = minQ.top();
          minQ.pop();
        }
      }
      arr1[start] = candidate;
      int operations = makeArrayIncreasing(arr1, start + 1, minQ);
      if (operations != -1 &&
          ((start == n - 1 || arr1[start] < arr1[start + 1]) &&
           (start == 0 || arr1[start] > arr1[start - 1]))) {
        return operations + 1;
      }
    } while (!minQ.empty());
    arr1[start] = initialValue;
    return -1;
  }
  int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    set<int> s(arr2.begin(), arr2.end());
    arr2.assign(s.begin(), s.end());
    priority_queue<int, vector<int>, greater<int>> minQ(arr2.begin(),
                                                        arr2.end());
    return makeArrayIncreasing(arr1, 0, minQ);
  }
};
class Optimal {
 public:
  int solve(int i, int j, int& a, int& b, int p, vector<vector<int>>& dp,
            vector<int>& v1, vector<int>& v2) {
    if (i == a) {
      return 0;
    }
    j = upper_bound(v2.begin() + j, v2.end(), p) - v2.begin();
    if (dp[i][j] != -1) return dp[i][j];
    if (j == b && v1[i] <= p) return 2001;
    int take = 2001, nottake = 2001;
    if (j != b) take = solve(i + 1, j + 1, a, b, v2[j], dp, v1, v2) + 1;
    if (v1[i] > p) nottake = solve(i + 1, j, a, b, v1[i], dp, v1, v2);
    return dp[i][j] = min(take, nottake);
  }
  int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size(), m = arr2.size();
    vector<vector<int>> dp(2001, vector<int>(2001, -1));
    sort(arr2.begin(), arr2.end());
    int a = solve(0, 0, n, m, -1, dp, arr1, arr2);
    if (a > n) return -1;
    return a;
  }
};
void printResult(const string label, vector<int>& arr1, vector<int>& arr2,
                 int result, double averageTime) {
  cout << "\n\tRemove Element (" << label << "), result = \t";
  cout << result << endl;
  cout << "\t\t\t\tArr 1 (size = " << arr1.size() << ")\t";
  Output::vectorPrint(arr1);
  cout << endl;
  cout << "\t\t\t\tArr 2 (size = " << arr2.size() << ")\t";
  Output::vectorPrint(arr2);
  cout << endl;
  cout << "\t\t\t\tAverage Time Taken: " << averageTime << endl;
}
int test(vector<int>& arr1, vector<int>& arr2) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nArray 1 (size = " << arr1.size() << ") = \t";
  Output::vectorPrint(arr1);

  cout << "\nArray 2 (size = " << arr2.size() << ") = \t";
  Output::vectorPrint(arr2);

  // cout << "\tMake Array Strictly Increasing (mine), result = \t";
  // cout << result.second << endl;
  // cout << "\t\t\t\tTime Taken: " << result.first << endl;

  // cout << "\tMake Array Strictly Increasing (optimal), result = \t";
  // cout << result.second << endl;
  // cout << "\t\t\t\tTime Taken: " << result.first << endl;
  // return 0;

  vector<int> arr1Copy;
  vector<int> arr2Copy;
  double totalTime = 0.0;
  int result;

  for (int i = 0; i < ITERATIONS; i++) {
    arr1Copy = arr1;
    arr2Copy = arr2;
    t.startClock();
    result = s.makeArrayIncreasing(arr1Copy, arr2Copy);
    double elapsed = static_cast<double>(t.stopClock());
    totalTime += elapsed;
  }
  totalTime = 0.0;
  for (int i = 0; i < ITERATIONS; i++) {
    arr1Copy = arr1;
    arr2Copy = arr2;
    t.startClock();
    result = s.makeArrayIncreasing(arr1Copy, arr2Copy);
    double elapsed = static_cast<double>(t.stopClock());
    totalTime += elapsed;
  }

  arr1Copy = arr1;
  arr2Copy = arr2;
  result = s.makeArrayIncreasing(arr1Copy, arr2Copy);
  printResult("solution", arr1Copy, arr2Copy, result, totalTime / ITERATIONS);

  for (int i = 0; i < ITERATIONS; i++) {
    arr1Copy = arr1;
    arr2Copy = arr2;
    t.startClock();
    result = o.makeArrayIncreasing(arr1Copy, arr2Copy);
    double elapsed = static_cast<double>(t.stopClock());
    totalTime += elapsed;
  }
  totalTime = 0.0;
  for (int i = 0; i < ITERATIONS; i++) {
    arr1Copy = arr1;
    arr2Copy = arr2;
    t.startClock();
    result = o.makeArrayIncreasing(arr1Copy, arr2Copy);
    double elapsed = static_cast<double>(t.stopClock());
    totalTime += elapsed;
  }

  arr1Copy = arr1;
  arr2Copy = arr2;
  result = o.makeArrayIncreasing(arr1Copy, arr2Copy);
  printResult("optimal", arr1Copy, arr2Copy, result, totalTime / ITERATIONS);
  return 0;
}
int main() {
  vector<int> x1;
  vector<int> x2;
  x1 = {9, 18, 3, 8, 21, 6, 7, 2, 7, 28, 23, 16, 33, 2, 25, 14, 15};
  x2 = {13, 2, 15, 30, 31, 30, 9,  10, 7, 30, 31, 4,  33, 10, 25, 28,
        19, 6, 15, 6,  19, 30, 25, 14, 7, 28, 23, 20, 1,  2,  25, 16};
  test(x1, x2);
  x1 = {5, 16, 19, 2, 1, 12, 7, 14, 5, 16};
  x2 = {6, 17, 4, 3, 6, 13, 4, 3, 18, 17, 16, 7, 14, 1, 16};
  test(x1, x2);
  x1 = {0, 11, 6, 1, 4, 3};
  x2 = {5, 4, 11, 10, 1, 0};
  test(x1, x2);
  x1 = {7, 6, 3, 0, 3};
  x2 = {9};
  test(x1, x2);
  x1 = {1, 5, 3, 6, 7};
  x2 = {1, 6, 3, 3};
  test(x1, x2);
  x1 = {1, 5, 3, 6, 7};
  x2 = {4, 3, 1};
  test(x1, x2);
  x1 = {1, 5, 3, 6, 7};
  x2 = {1, 3, 2, 4};
  test(x1, x2);
  return 0;
}