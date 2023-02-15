#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    for (auto it1 = nums.begin(); it1 != nums.end(); it1++) {
      int new_target = target - *it1;
      for (auto it2 = it1 + 1; it2 != nums.end(); it2++) {
        int remainder = new_target - *it2;
        if (remainder == 0) {
          result.push_back(it1 - nums.begin());
          result.push_back(it2 - nums.begin());
          return result;
        }
      }
    }
    return result;
  }
};
int main() {
  Solution s = Solution();
  vector<int> vec = {0, 1, 2, 3, 4};
  vector<int> res = s.twoSum(vec, 3);
  for (vector<int>::iterator it = res.begin(); it != res.end(); it++) {
    cout << *it << endl;
  }
  return 0;
}