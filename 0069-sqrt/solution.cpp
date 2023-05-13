#include "../modules/index.h"
#define ITERATIONS 50
class Solution {
 public:
  int sq(int x) { return x * x; }
  int mySqrt(int x) {
    if (x == 1) return x;
    int hi = x, lo = 0;
    int guess = (hi + lo) / 2;
    while (!(sq(guess) <= x && sq(guess + 1) > x)) {
      if (sq(guess) < x) {
        lo = guess;
      } else {
        hi = guess;
      }
      guess = (hi + lo) / 2;
    }
    return guess;
  }
};

int test(int x) {
  Solution s = Solution();
  cout << "\nX = " << x << endl;

  auto result = measureMethodPerformance(ITERATIONS, &Solution::mySqrt, s, x);
  cout << "\tMySqrt = " << result.second << "\tTime Taken: " << result.first
       << endl;

  auto sqrtFunction = [](int x) { return sqrt(x); };
  result = measureFunctionPerformance(ITERATIONS, sqrtFunction, x);
  cout << "\tSqrt = " << result.second << "\tTime Taken: " << result.first
       << endl;

  return 0;
}
int main() {
  test(1);
  test(2);
  test(7);
  test(76789);
  test(79678);
  return 0;
}