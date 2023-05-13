#include "../modules/index.h"
#define ITERATIONS 50
class Solution {
 private:
  vector<int> fib = {0, 0, 1};

 public:
  int fibonacci(int x) {
    if (x < fib.size()) return fib[x];
    int result = fibonacci(x - 1) + fibonacci(x - 2);
    fib.push_back(result);
    return fib[x];
  }
  int climbStairs(int x) { return fibonacci(x + 2); }
};

int test(int x) {
  Solution s = Solution();
  cout << "\nX = " << x << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::climbStairs, s, x);
  cout << "\tMyClimbStairs = " << result.second
       << "\t\t\t\tTime Taken: " << result.first << endl;

  return 0;
}
int main() {
  for (int i = 1; i < 45; i++) {
    test(i);
  }
  return 0;
}