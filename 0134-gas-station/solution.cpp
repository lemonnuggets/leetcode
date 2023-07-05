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
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int start = 0;
    int pathLength = 1;
    int currTank = gas[0] - cost[0];
    while (pathLength < n) {
      if (currTank < 0) {
        start = (start - 1 + n) % n;
        currTank += gas[start] - cost[start];
      } else {
        int currEndIndex = (start + pathLength) % n;
        currTank += gas[currEndIndex] - cost[currEndIndex];
      }
      pathLength++;
    }
    if (currTank < 0) return -1;
    return start;
  }
};
class Optimal {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int total_surplus = 0;
    int surplus = 0;
    int start = 0;

    for (int i = 0; i < n; i++) {
      total_surplus += gas[i] - cost[i];
      surplus += gas[i] - cost[i];
      if (surplus < 0) {
        surplus = 0;
        start = i + 1;
      }
    }
    return (total_surplus < 0) ? -1 : start;
  }
};
int test(vector<int>& gas, vector<int>& cost) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\ngas (size = " << gas.size() << ") = \t";
  // Output::vectorPrint(gas);
  cout << "\ncost (size = " << cost.size() << ") = \t";
  // Output::vectorPrint(cost);
  cout << endl;

  auto result = measureMethodPerformance(
      ITERATIONS, &Solution::canCompleteCircuit, s, gas, cost);
  cout << "\tcanCompleteCircuit (mine), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::canCompleteCircuit, o,
                                    gas, cost);
  cout << "\tcanCompleteCircuit (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int getRandInt(int min, int max) {
  static const double fraction = 1.0 / (RAND_MAX + 1.0);
  return min + static_cast<int>((max - min + 1) * (rand() * fraction));
}
vector<int> getRandVector(int size, int min, int max) {
  vector<int> v;
  for (int i = 0; i < size; i++) {
    v.push_back(getRandInt(min, max));
  }
  return v;
}
int main() {
  vector<int> gas, cost;
  gas = {3, 1, 1};
  cost = {1, 2, 2};
  test(gas, cost);
  gas = {5, 1, 2, 3, 4};
  cost = {4, 4, 1, 5, 1};
  test(gas, cost);
  gas = {1, 2, 3, 4, 5};
  cost = {3, 4, 5, 1, 2};
  test(gas, cost);
  gas = {2, 3, 4};
  cost = {3, 4, 3};
  test(gas, cost);
  gas = getRandVector(10000, 1, 100);
  cost = getRandVector(10000, 1, 100);
  test(gas, cost);
  gas = getRandVector(10000, 1, 100);
  cost = getRandVector(10000, 1, 100);
  test(gas, cost);
  gas = getRandVector(10000, 1, 100);
  cost = getRandVector(10000, 1, 100);
  test(gas, cost);
  gas = getRandVector(10000, 1, 100);
  cost = getRandVector(10000, 1, 100);
  test(gas, cost);
  gas = getRandVector(10000, 1, 100);
  cost = getRandVector(10000, 1, 100);
  test(gas, cost);
  return 0;
}
