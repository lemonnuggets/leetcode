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
  bool isHappyRecurse(int n, set<int>& seen) {
    int sum = 0, digit;
    while (n > 0) {
      digit = n % 10;
      sum += digit * digit;
      n /= 10;
    }
    if (sum == 1) {
      return true;
    }
    if (seen.count(sum) > 0) {
      return false;
    }
    seen.insert(sum);
    return isHappyRecurse(sum, seen);
  }
  bool isHappy(int n) {
    set<int> seen;
    return isHappyRecurse(n, seen);
  }
};
class Optimal {
  // Brent's Cycle detection algorithm
  // Brent's algorithm features a moving rabbit and a stationary, then
  // teleporting, turtle. Both turtle and rabbit start at the top of the list.
  // The rabbit takes one step per iteration. Every once in a while, we teleport
  // the turtle to the rabbit's position, and let the rabbit continue moving. We
  // start out waiting just 2 steps before teleportation, and we double that
  // each time we move the turtle. If there is a loop, they will meet in the
  // loop.

  // Can also use Floyd's Cycle detection algorithm but Brent's algo has
  //  upper bound for steps as Floyd's algo.
 public:
  int next(int n) {
    int sum = 0;

    while (n != 0) {
      sum += pow(n % 10, 2);
      n = n / 10;
    }

    return sum;
  }
  bool isHappy(int n) {
    int slow = n;
    int fast = next(n);
    int cnt = 1;
    int lim = 2;

    while (slow != fast) {
      if (cnt == lim) {
        cnt = 1;
        lim = lim * 2;
        slow = fast;
      } else
        cnt++;

      fast = next(fast);
    }

    return fast == 1;
  }
};
int test(int argument) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nArgument = " << argument << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::isHappy, s, argument);
  cout << "\tisHappy (mine), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::isHappy, o, argument);
  cout << "\tisHappy (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  int n;
  n = 19;
  test(n);
  n = 2;
  test(n);
  return 0;
}