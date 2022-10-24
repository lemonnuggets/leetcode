#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int newSize = 0;
    for (auto it = nums.begin() + 1; it != nums.end(); it++) {
      if (*it != *(it - 1)) {
        nums[newSize++] = *it;
      }
    }
    return newSize;
  }
};
string vecString(vector<int>& nums, int k) {
  string result = "";
  for (int i = 0; i < k; i++) {
    result += to_string(nums[i]) + " ";
  }
  return result;
}
int main() {
  Solution s = Solution();
  vector<int> ra1{1, 1, 2};
  int k1 = s.removeDuplicates(ra1);
  vector<int> ra2{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int k2 = s.removeDuplicates(ra2);
  cout << k1 << "\t" << vecString(ra1, k1) << endl;
  cout << k2 << "\t" << vecString(ra2, k2) << endl;
  return 0;
}