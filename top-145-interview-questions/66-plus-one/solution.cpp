#include "../modules/index.h"
class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
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
  vector<int> plusOne(vector<int>& digits) {
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
  Timer t = Timer();
  int duration;

  cout << "\nX (size = " << x.size() << ") = \t";
  Output::vector(x);
  cout << endl;

  vector<int> result;
  t.startClock();
  vector<int> x1(x.begin(), x.end());
  result = s.plusOne(x1);
  duration = t.stopClock();

  cout << "\tPlus One (mine), result = \t";
  Output::vector(result);
  cout << "\t\t\t\tTime Taken: " << duration << endl;

  t.startClock();
  vector<int> x2(x.begin(), x.end());
  result = o.plusOne(x2);
  duration = t.stopClock();

  cout << "\tPlus One (optimal), result = \t";
  Output::vector(result);
  cout << "\t\t\t\tTime Taken: " << duration << endl;
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