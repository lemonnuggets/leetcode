#include <bits/stdc++.h>
using namespace std;
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