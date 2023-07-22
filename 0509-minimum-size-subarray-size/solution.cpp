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
  int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int i = 0, j = 0, rollingTotal = 0;
    while (rollingTotal < target && j < n) {
      rollingTotal += nums[j++];
    }
    if (rollingTotal < target) {
      return 0;
    }
    int minLen = j;
    while (i < j) {
      rollingTotal -= nums[i++];
      while (rollingTotal > target) {
        rollingTotal -= nums[--j];
      }
      while (j < n && rollingTotal < target) {
        rollingTotal += nums[j++];
      }
      if (rollingTotal < target) break;
      minLen = min(j - i, minLen);
    }
    return minLen;
  }
};
class Optimal {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int p = 0, q = 0, sum = 0, gmin = INT_MAX;
    for (q = 0; q < nums.size(); q++) {
      sum += nums[q];
      while (sum >= target) {
        gmin = min(q - p + 1, gmin);
        sum -= nums[p];
        p++;
      }
    }
    if (gmin == INT_MAX) return 0;
    return gmin;
  }
};
int test(int target, vector<int>& nums) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\ntarget = " << target;
  cout << "\nnums (size = " << nums.size() << ") = \t";
  if (nums.size() < 100) {
    Output::vectorPrint(nums);
  }
  cout << endl;

  auto result = measureMethodPerformance(ITERATIONS, &Solution::minSubArrayLen,
                                         s, target, nums);
  cout << "\tminSubArrayLen (mine), result = \t\t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::minSubArrayLen, o,
                                    target, nums);
  cout << "\tminSubArrayLen (optimal), result = \t\t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  int target;
  vector<int> x;
  target = 5;
  x = {1, 1, 1, 1, 1, 3, 2};
  test(target, x);
  target = 7;
  x = {2, 3, 1, 2, 4, 3};
  test(target, x);
  target = 80;
  x = {10, 5, 13, 4, 8, 4, 5, 11, 14, 9, 16, 10, 20, 8};
  test(target, x);
  target = 11;
  x = {1, 2, 3, 4, 5};
  test(target, x);
  target = 4;
  x = {1, 4, 4};
  test(target, x);
  target = 11;
  x = {1, 1, 1, 1, 1, 1, 1, 1};
  test(target, x);
  return 0;
}