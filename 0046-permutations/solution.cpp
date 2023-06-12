#include "../modules/index.h"
#define ITERATIONS 50
class Solution {
 private:
  void inner_permute(vector<vector<int>>& permutations, vector<int>& nums,
                     int start, int end) {
    if (end < start || end > nums.size()) return;
    if (end == start) {
      permutations.push_back(nums);
      return;
    }
    if (end - start == 1) {
      permutations.push_back(nums);
      swap(nums[start], nums[end]);
      permutations.push_back(nums);
      swap(nums[start], nums[end]);
      return;
    }

    inner_permute(permutations, nums, start + 1, end);
    int j = start + 1;
    while (j <= end) {
      swap(nums[start], nums[j]);
      inner_permute(permutations, nums, start + 1, end);
      swap(nums[start], nums[j]);
      j++;
    }
  }

 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> permutations;
    inner_permute(permutations, nums, 0, nums.size() - 1);
    return permutations;
  }
};
class Optimal {
 private:
  void inner_permute(vector<vector<int>>& permutations, vector<int>& nums,
                     int start) {
    int end = nums.size() - 1;
    if (end <= start) {
      permutations.push_back(nums);
      return;
    }

    int j = start;
    while (j <= end) {
      swap(nums[start], nums[j]);
      inner_permute(permutations, nums, start + 1);
      swap(nums[start], nums[j]);
      j++;
    }
  }

 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> permutations;
    int required_size = 1;
    int n = nums.size();
    while (n > 0) {
      required_size *= n--;
    }
    permutations.reserve(required_size);
    inner_permute(permutations, nums, 0);
    return permutations;
  }
};
int test(vector<int>& nums) {
  Solution s = Solution();
  Optimal o = Optimal();

  cout << "\nNums (size = " << nums.size() << ") = \t";
  Output::vectorPrint(nums);
  cout << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::permute, s, nums);
  cout << "\tPermute (mine), result (size = " << result.second.size()
       << ") = \t";
  Output::vectorPrint(result.second);
  cout << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::permute, o, nums);
  cout << "\tPermute (mine), result (size = " << result.second.size()
       << ") = \t";
  Output::vectorPrint(result.second);
  cout << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  vector<int> x = {1, 2, 3, 4, 5, 6};
  test(x);
  x = {1, 2, 3, 4, 5};
  test(x);
  x = {1, 2, 3, 4};
  test(x);
  x = {1, 2, 3};
  test(x);
  x = {0, 1};
  test(x);
  x = {1};
  test(x);
  return 0;
}