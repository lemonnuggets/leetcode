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
  bool isSubsequence(string s, string t) {
    int sPtr = 0, tPtr = 0, sN = s.size(), tN = t.size();
    while (sPtr < sN && tPtr < tN) {
      if (s[sPtr] == t[tPtr]) {
        sPtr++;
      }
      tPtr++;
    }
    return sPtr >= sN;
  }
};
class Optimal {
 public:
  bool isSubsequence(string s, string t) {
    int sPtr = 0, tPtr = 0, sN = s.size(), tN = t.size();
    while (sPtr < sN && tPtr < tN) {
      if (s[sPtr] == t[tPtr]) {
        sPtr++;
      }
      tPtr++;
    }
    return sPtr >= sN;
  }
};
int test(string arg1, string arg2) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\narg1 (size = " << arg1.size() << ") = \t";
  cout << arg1 << endl;
  cout << "\narg2 (size = " << arg2.size() << ") = \t";
  cout << arg2 << endl;

  auto result = measureMethodPerformance(ITERATIONS, &Solution::isSubsequence,
                                         s, arg1, arg2);
  cout << "\tisSubsequence (mine), result = \t\t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::isSubsequence, o,
                                    arg1, arg2);
  cout << "\tisSubsequence (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  string s, t;
  s = "abc";
  t = "ahbgdc";
  test(s, t);
  s = "axc";
  t = "ahbgdc";
  test(s, t);
  return 0;
}