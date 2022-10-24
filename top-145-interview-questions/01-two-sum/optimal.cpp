#include <bits/stdc++.h>
using namespace std;
// Uses a map as a hash to store <key, value> pair,
// as <value of vector element, index of vector element>
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    // Key is the number and value is its index in the vector.
    unordered_map<int, int> hash;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
      int numberToFind = target - nums[i];

      // if numberToFind is found in map, return them
      if (hash.find(numberToFind) != hash.end()) {
        //+1 because indices are NOT zero based
        result.push_back(hash[numberToFind] + 1);
        result.push_back(i + 1);
        return result;
      }

      // number was not found. Put it's index in the map.
      hash[nums[i]] = i;
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