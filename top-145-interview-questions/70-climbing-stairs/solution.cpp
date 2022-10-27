#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
class Timer {
  high_resolution_clock::time_point start;
  high_resolution_clock::duration duration;

 public:
  high_resolution_clock::time_point startClock() {
    this->start = high_resolution_clock::now();
    return this->start;
  }
  high_resolution_clock::rep stopClock() {
    high_resolution_clock::time_point stop = high_resolution_clock::now();
    this->duration = duration_cast<microseconds>(stop - this->start);
    return this->duration.count();
  }
};
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
  Timer t = Timer();
  int duration;
  cout << "\nX = " << x << endl;

  t.startClock();
  int r1 = s.climbStairs(x);
  duration = t.stopClock();
  cout << "\tMyClimbStairs = " << r1 << "\t\t\t\tTime Taken: " << duration
       << endl;

  return 0;
}
int main() {
  for (int i = 1; i < 45; i++) {
    test(i);
  }
  return 0;
}