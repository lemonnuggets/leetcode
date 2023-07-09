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
  string scheme(int n, char a, char b, char c) {
    if (n == 0) {
      return "";
    }
    if (n == 4) {
      return string(1, a) + string(1, b);
    }
    if (n == 9) {
      return string(1, a) + string(1, c);
    }
    return string(n / 5, b) + string(n % 5, a);
  }
  string thousandsToRoman(int n) { return scheme(n, 'M', '_', '_'); }
  string hundredsToRoman(int n) { return scheme(n, 'C', 'D', 'M'); }
  string tensToRoman(int n) { return scheme(n, 'X', 'L', 'C'); }
  string onesToRoman(int n) { return scheme(n, 'I', 'V', 'X'); }
  string intToRoman(int n) {
    int ones = n % 10;
    n /= 10;
    int tens = n % 10;
    n /= 10;
    int hundreds = n % 10;
    n /= 10;
    int thousands = n % 10;
    string thousandsString = thousandsToRoman(thousands);
    string hundredsString = hundredsToRoman(hundreds);
    string tensString = tensToRoman(tens);
    string onesString = onesToRoman(ones);
    return thousandsString + hundredsString + tensString + onesString;
  }
};
class Optimal {
 public:
  string scheme(int n, char a, char b, char c) {
    if (n == 4) {
      return ("" + a) + b;
    }
    if (n = 9) {
      return ("" + a) + c;
    }
    return string(n / 5, b) + string(n % 5, a);
  }
  string tensToRoman(int n) { return scheme(n, 'X', 'L', 'C'); }
  string onesToRoman(int n) { return scheme(n, 'I', 'V', 'X'); }
  string intToRoman(int n) {
    int ones = n % 10;
    n /= 10;
    int tens = n % 10;
    n /= 10;
    int hundreds = n % 10;
    n /= 10;
    int thousands = n % 10;
    return tensToRoman(tens) + onesToRoman(ones);
  }
};
int test(int n) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nn = ";
  cout << n << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::intToRoman, s, n);
  cout << "\tintToRoman (mine), result = \t\t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::intToRoman, o, n);
  cout << "\tintToRoman (optimal), result = \t\t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  int x;
  x = 1994;
  test(x);
  x = 1;
  test(x);
  x = 3;
  test(x);
  x = 58;
  test(x);
  return 0;
}