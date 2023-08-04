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
  int longestConsecutive(vector<int>& nums) {
    int n = nums.size();
    if (n <= 0) {
      return 0;
    }
    map<int, bool> counts;
    for (int i = 0; i < n; i++) {
      counts[nums[i]] = true;
    }
    int prev = INT_MIN, longest = 0, curr = 0;
    for (auto c : counts) {
      if (prev == INT_MIN || c.first - prev != 1) {
        if (curr + 1 > longest) {
          longest = curr + 1;
        }
        prev = c.first;
        curr = 0;
        continue;
      }
      prev = c.first;
      curr++;
    }
    if (curr + 1 > longest) {
      longest = curr + 1;
    }
    return longest;
  }
};
class Optimal {
 public:
  int longestConsecutive(vector<int>& nums) {
    // from leetcode
    int cnt = 1, maxCnt = 0;
    if (nums.size() == 0) return 0;

    sort(nums.begin(), nums.end());

    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1]) {
        continue;
      }
      if (nums[i] == nums[i - 1] + 1) {
        cnt++;
      } else {
        maxCnt = max(maxCnt, cnt);
        cnt = 1;
      }
    }

    if (cnt) {
      maxCnt = max(cnt, maxCnt);
    }
    return maxCnt;
  }
};
int test(vector<int>& nums) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nnums (size = " << nums.size() << ") = \t";
  if (nums.size() < 100) {
    Output::vectorPrint(nums);
  }
  cout << endl;

  auto result = measureMethodPerformance(
      ITERATIONS, &Solution::longestConsecutive, s, nums);
  cout << "\tlongestConsecutive (mine), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::longestConsecutive, o,
                                    nums);
  cout << "\tlongestConsecutive (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  vector<int> nums;
  nums = {9, 1, -3, 2, 4, 8, 3, -1, 6, -2, -4, 7};
  test(nums);
  nums = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
  test(nums);
  nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  test(nums);
  nums = {100, 4, 200, 1, 2, 3};
  test(nums);
  return 0;
}