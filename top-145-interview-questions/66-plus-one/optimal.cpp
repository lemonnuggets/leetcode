#include <bits/stdc++.h>
using namespace std;
class Solution {
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
string vecString(vector<int>& nums, int k = -1) {
  if (k < 0) k = nums.size();
  string result = "";
  for (int i = 0; i < k; i++) {
    result += to_string(nums[i]) + " ";
  }
  return result;
}
int main() {
  Solution s = Solution();
  vector<int> ra1{1, 2, 3};
  vector<int> result1 = s.plusOne(ra1);
  cout << vecString(result1) << endl;

  vector<int> ra2{4, 3, 2, 1};
  vector<int> result2 = s.plusOne(ra2);
  cout << vecString(result2) << endl;

  vector<int> ra3{9};
  vector<int> result3 = s.plusOne(ra3);
  cout << vecString(result3) << endl;
  return 0;
}