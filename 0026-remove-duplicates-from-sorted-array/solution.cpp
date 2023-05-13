#include "../modules/index.h"
#define ITERATIONS 50
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
int test(vector<int>& x) {
  Solution s = Solution();

  cout << "\nX (size = " << x.size() << ") = \t";
  Output::vectorPrint(x);
  cout << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::removeDuplicates, s, x);

  cout << "\tMyClimbStairs = " << result.second
       << "\t\t\t\tTime Taken: " << result.first << endl;

  return 0;
}
int main() {
  Solution s = Solution();
  vector<int> x;
  x = {1, 1, 2};
  test(x);
  x = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  test(x);
  return 0;
}