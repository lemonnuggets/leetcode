// https://oeis.org/A252864
// Due to a mistake, I ended up writing code to generate the above sequence
// instead of the sequence required in question 0070-climbing-stairs

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
 public:
  void printSetOfPairs(set<pair<int, int>> s) {
    cout << endl;
    cout << "\t\t";
    for (auto it = s.begin(); it != s.end(); it++) {
      cout << "(" << it->first << ", " << it->second << ");\t";
    }
    cout << endl;
  }
  set<pair<int, int>> g(int n) {
    set<pair<int, int>> s;
    if (n == 0) {
      pair<int, int> a;
      a.first = 0;
      a.second = 0;
      s.emplace(a);
      return s;
    }

    s = g(n - 1);
    set<pair<int, int>> t;
    for (auto it = s.begin(); it != s.end(); it++) {
      int j = it->first, k = it->second;
      pair<int, int> a = make_pair(j, k + 1), b = make_pair(k, j + k);
      t.emplace(a);
      t.emplace(b);
    }
    set<pair<int, int>> result;
    set_difference(t.begin(), t.end(), s.begin(), s.end(),
                   inserter(result, result.begin()));
    return result;
  }
  int climbStairs(int x) { return g(x - 1).size(); }
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

  // t.startClock();
  // set<pair<int, int>> r1 = s.g(x);
  // duration = t.stopClock();
  // cout << "\tg(" << x << ") = ";
  // s.printSetOfPairs(r1);
  // cout << "\t\t\t\tTime Taken: " << duration << endl;

  return 0;
}
int main() {
  for (int i = 1; i < 10; i++) {
    test(i);
  }
  return 0;
}

// Trying out stuff
// 0 => 1  ()

// 1 => 1  (1)
//      +1
// 2 => 2  (1+1, 2)
//      +1
// 3 => 3  (1+1+1, 2+1, 1+2)
//      +2
// 4 => 5  (1+1+1+1, 2+1+1, 1+2+1, 1+1+2, 2+2)
//   +3 +3
// 5 => 8  (1+1+1+1+1, 2+1+1+1, 1+2+1+1, 1+1+2+1, 1+1+1+2, 1+2+2, 2+1+2,
// 2+2+1)
//   +6 +4
// 6 => 12  (1+1+1+1+1+1, 2+1+1+1+1, 1+2+1+1+1, 1+1+2+1+1, 1+1+1+2+1,
// 1+1+1+1+2, 1+1+2+2, 1+2+1+2, 1+2+2+1, 2+1+2+1, 2+2+1+1, 2+2+2)
//   +11 +6
// 7 => 18  (1+1+1+1+1+1+1, 2+1+1+1+1+1, 1+2+1+1+1+1, 1+1+2+1+1+1,
// 1+1+1+2+1+1, 1+1+1+1+2+1, 1+1+1+1+1+2, 1+1+1+2+2, 1+1+2+1+2, 1+1+2+2+1,
// 1+2+1+2+1, 1+2+2+1+1, 2+1+2+1+1, 2+2+1+1+1, 2+2+2+1, 2+2+1+2, 2+1+2+2,
// 1+2+2+2)
//   +17 +7
// 8 => 25  (1+1+1+1+1+1+1+1, 2+1+1+1+1+1+1, 1+2+1+1+1+1+1, 1+1+2+1+1+1+1,
// 1+1+1+2+1+1+1, 1+1+1+1+2+1+1, 1+1+1+1+1+2+1, 1+1+1+1+1+1+2, 1+1+1+1+2+2,
// 1+1+1+2+1+2, 1+1+1+2+2+1, 1+1+2+1+2+1, 1+1+2+2+1+1, 1+2+1+2+1+1,
// 1+2+2+1+1+1, 2+1+2+1+1+1, 2+2+1+1+1+1, 2+2+2+1+1, 2+2+1+2+1, 2+1+2+2+1,
// 1+2+2+2+1, 1+2+2+1+2, 1+2+1+2+2, 1+1+2+2+2, 2+2+2+2)

// 9 => 35  (1+1+1+1+1+1+1+1+1, 2+1+1+1+1+1+1+1, 1+2+1+1+1+1+1+1,
// 1+1+2+1+1+1+1+1, 1+1+1+2+1+1+1+1, 1+1+1+1+2+1+1+1, 1+1+1+1+1+2+1+1,
// 1+1+1+1+1+1+2+1, 1+1+1+1+1+1+1+2, 1+1+1+1+1+2+2, 1+1+1+1+2+1+2,
// 1+1+1+1+2+2+1, 1+1+1+2+1+2+1, 1+1+1+2+2+1+1, 1+1+2+1+2+1+1, 1+1+2+2+1+1+1,
// 1+2+1+2+1+1+1, 1+2+2+1+1+1+1, 2+1+2+1+1+1+1, 2+2+1+1+1+1+1, 2+2+2+1+1+1,
// 2+2+1+2+1+1, 2+1+2+2+1+1, 1+2+2+2+1+1, 1+2+2+1+2+1, 1+2+1+2+2+1,
// 1+1+2+2+2+1,1+1+2+2+1+2,1+1+2+1+2+2,1+1+1+2+2+2,1+2+2+2+2,2+1+2+2+2,2+2+1+2+2,2+2+2+1+2,
// 2+2+2+2+1)