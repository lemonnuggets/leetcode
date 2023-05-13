#include "../modules/index.h"
#define ITERATIONS 50
class Solution {
 public:
  vector<int> plusOne(const vector<int>& d) {
    // create a copy of the input vector
    vector<int> digits = d;
    int carry = 1;
    for (auto it = digits.end() - 1; it != digits.begin() - 1; it--) {
      int sum = carry + *it;
      if (sum >= 10) {
        *it = sum - 10;
        carry = 1;
      } else {
        *it = sum;
        carry = 0;
      }
    }
    if (carry > 0) digits.insert(digits.begin(), carry);
    return digits;
  }
};
class Optimal {
 public:
  vector<int> plusOne(const vector<int>& d) {
    // create a copy of the input vector
    vector<int> digits = d;
    int n = digits.size() - 1;

    for (int i = n; i >= 0; --i) {
      // traverse digits from the last element (least significant)
      // since we begin with the last digit, increasing that digit by one
      // results in overflow.  Therefore, all elements PRIOR to digits[0]
      // need to be considered since there may be additional nines between
      // digits[0], ... , digits[n].
      if (digits[i] == 9) {
        digits[i] = 0;
      } else {  // current digit is not 9 so we can safely increment by one
        digits[i] += 1;
        return digits;
      }
    }
    // if the program runs to this point, each 9 is now a 0.
    // to get a correct solution, we need to add one more element with
    // a value of zero AND set digits[0] to 1 (in the most significant position)
    // to account for the carry digit.
    digits.push_back(0);
    digits[0] = 1;
    return digits;
  }
};

int test(vector<int>& x) {
  Solution s = Solution();
  Optimal o = Optimal();

  cout << "\nX (size = " << x.size() << ") = \t";
  Output::vectorPrint(x);
  cout << endl;

  auto result = measureMethodPerformance(ITERATIONS, &Solution::plusOne, s, x);
  cout << "\tPlus One (mine), result = \t";
  Output::vectorPrint(result.second);
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::plusOne, o, x);
  cout << "\tPlus One (optimal), result = \t";
  Output::vectorPrint(result.second);
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  vector<int> x;
  x = {1, 2, 3};
  test(x);

  x = {4, 3, 2, 1};
  test(x);

  x = {9};
  test(x);
  return 0;
}