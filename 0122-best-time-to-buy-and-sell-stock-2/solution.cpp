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
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int totalProfit = 0;
    for (int i = 0; i < n - 1; i++) {
      if (prices[i + 1] > prices[i]) {
        totalProfit += prices[i + 1] - prices[i];
      }
    }
    return totalProfit;
  }
};
class Optimal {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int totalProfit = 0;
    for (int i = 0; i < n - 1; i++) {
      // max has better perf than if? no according to local testing
      totalProfit += max(0, prices[i + 1] - prices[i]);
    }
    return totalProfit;
  }
};

int test(vector<int>& prices) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nprices (size = " << prices.size() << ") = \t";
  // Output::vectorPrint(prices);
  cout << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::maxProfit, s, prices);
  cout << "\tMax Profit (mine), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::maxProfit, o, prices);
  cout << "\tMax Profit (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
vector<int> generateRandomVector(int size) {
  vector<int> result = vector<int>(size);
  for (int i = 0; i < size; i++) {
    result[i] = rand() % 100;
  }
  return result;
}
int main() {
  vector<int> x = {7, 1, 5, 3, 6, 4};
  test(x);
  x = {1, 2, 3, 4, 5};
  test(x);
  x = {7, 6, 4, 3, 1};
  test(x);
  x = generateRandomVector(1000000);
  test(x);
  return 0;
}
