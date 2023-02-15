#include "../../modules/index.h"
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
  Timer t = Timer();
  int duration;
  cout << "\nX = " << x << endl;

  t.startClock();
  int r1 = s.mySqrt(x);
  duration = t.stopClock();
  cout << "\tMySqrt = " << r1 << "\tTime Taken: " << duration << endl;

  t.startClock();
  int r2 = sqrt(x);
  duration = t.stopClock();
  cout << "\tSqrt = " << r2 << "\tTime Taken: " << duration << endl;

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