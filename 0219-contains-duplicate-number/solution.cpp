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
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> counts;
    int n = nums.size();
    int i = 0, j = 0;
    while (j <= k && j < n) {
      counts[nums[j]]++;
      if (counts[nums[j]] > 1) {
        return true;
      }
      j++;
    }
    j--;
    while (j < n - 1) {
      counts[nums[i++]]--;
      counts[nums[++j]]++;
      if (counts[nums[j]] > 1) {
        return true;
      }
    }
    return false;
  }
};
class Optimal {
 public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    // slower for large n
    int n = nums.size();
    bool res = false;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n && j - i <= k; j++) {
        if (nums[i] == nums[j]) {
          return true;
        }
      }
    }
    return false;
  }
};
int test(vector<int>& nums, int k) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nk = \t\t\t" << k;
  cout << "\nnums (size = " << nums.size() << ") = \t";
  if (nums.size() < 100) {
    Output::vectorPrint(nums);
  }
  cout << endl;

  auto result = measureMethodPerformance(
      ITERATIONS, &Solution::containsNearbyDuplicate, s, nums, k);
  cout << "\tcontainsNearbyDuplicate (mine), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(
      ITERATIONS, &Optimal::containsNearbyDuplicate, o, nums, k);
  cout << "\tcontainsNearbyDuplicate (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  vector<int> nums;
  int k;
  nums = {1, 0, 1, 1};
  k = 1;
  test(nums, k);
  nums = {1};
  k = 1;
  test(nums, k);
  nums = {1, 2, 3, 1};
  k = 3;
  test(nums, k);
  nums = {1, 2, 3, 1, 2, 3};
  k = 2;
  test(nums, k);
  nums = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1,
          2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2,
          3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3};
  k = 2;
  test(nums, k);
  return 0;
}