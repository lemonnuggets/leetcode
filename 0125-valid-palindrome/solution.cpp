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
  bool isPalindrome(string s) {
    int n = s.size();
    int lo = 0, hi = n - 1;
    char a, b;
    while (lo < hi && lo < n && hi >= 0) {
      while (lo < n && !isalnum(s[lo])) lo++;
      while (hi > 0 && !isalnum(s[hi])) hi--;
      if (lo >= hi) {
        break;
      }
      if (isupper(s[lo])) {
        a = tolower(s[lo]);
      } else {
        a = s[lo];
      }
      if (isupper(s[hi])) {
        b = tolower(s[hi]);
      } else {
        b = s[hi];
      }

      if (a != b) {
        return false;
      }

      lo++;
      hi--;
    }
    return true;
  }
};
class Optimal {
 public:
  bool isPalindrome(string s) {
    int n = s.size();
    int lo = 0, hi = n - 1;
    char a, b;
    while (lo < hi && lo < n && hi >= 0) {
      while (lo < n && !isalnum(s[lo])) lo++;
      while (hi > 0 && !isalnum(s[hi])) hi--;

      if (isupper(s[lo])) {
        a = tolower(s[lo]);
      } else {
        a = s[lo];
      }
      if (isupper(s[hi])) {
        b = tolower(s[hi]);
      } else {
        b = s[hi];
      }

      if (a != b) {
        return false;
      }

      lo++;
      hi--;
    }
    return true;
  }
};
int test(string argument) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nArgument (size = " << argument.size() << ") = \t";
  cout << argument << endl;

  auto result = measureMethodPerformance(ITERATIONS, &Solution::isPalindrome, s,
                                         argument);
  cout << "\tisPalindrome (mine), result = \t\t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result =
      measureMethodPerformance(ITERATIONS, &Optimal::isPalindrome, o, argument);
  cout << "\tisPalindrome (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  string x;
  x = ".,";
  test(x);
  x = "A man, a plan, a canal: Panama";
  test(x);
  x = "race a car";
  test(x);
  x = " ";
  test(x);
  return 0;
}