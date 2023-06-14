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
    int bestProfit = 0;
    int highestPrice = prices[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      highestPrice = max(prices[i], highestPrice);
      bestProfit = max(bestProfit, highestPrice - prices[i]);
    }
    return bestProfit;
  }
};
class Optimal {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();

    int min = 0, profit = 0;
    for (int i = 0; i < n; i++) {
      if (profit < (prices[i] - prices[min]))
        profit = (prices[i] - prices[min]);
      if (prices[min] > prices[i]) min = i;
    }
    return profit;
  }
};

int test(vector<int>& prices) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nprices (size = " << prices.size() << ") = \t";
  Output::vectorPrint(prices);
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
  x = {7, 6, 4, 3, 1};
  test(x);
  x = generateRandomVector(10000);
  test(x);
  return 0;
}
