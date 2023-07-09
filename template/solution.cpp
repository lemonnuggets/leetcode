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
  void func(void) {}
};
class Optimal {
 public:
  void func(void) {}
};
int test(string argument) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nArgument (size = " << argument.size() << ") = \t";
  cout << argument << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::func, s, argument);
  cout << "\tFunc (mine), result = \t\t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::func, o, argument);
  cout << "\tFunc (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  string x = "Hello World!";
  test(x);
  return 0;
}