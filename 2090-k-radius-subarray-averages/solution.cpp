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
  vector<int> getAverages(vector<int>& nums, int k) {
    const int n = nums.size();
    const double fraction = 1 / (double)(2 * k + 1);
    double rollingTotal = 0;
    vector<int> result(n, -1);
    for (int i = 0; i < 2 * k && i < n; ++i) {
      rollingTotal += nums[i];
    }
    for (int i = k; i + k < n; i++) {
      rollingTotal +=
          i - k == 0 ? nums[i + k] : (nums[i + k] - nums[i - k - 1]);
      result[i] = rollingTotal * fraction;
    }
    return result;
  }
};
class Optimal {
 public:
  vector<int> getAverages(vector<int>& nums, int k) {
    int n = nums.size(), start = 0;
    long sum = 0;
    vector<int> result(n, -1);
    const int window_size = k + k + 1;
    const int double_k = k + k;
    for (int end = 0; end < n; ++end) {
      sum += nums[end];
      if (end >= double_k) {
        result[start + k] = sum / window_size;
        sum -= nums[start++];
      }
    }
    return result;
  }
};
int test(vector<int>& nums, int k) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nk = \t" << k << endl;
  cout << "\nNums (size = " << nums.size() << ") = \t";
  if (nums.size() < 100) Output::vectorPrint(nums);
  cout << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::getAverages, s, nums, k);
  cout << "\tgetAverages (mine), result = \t";
  if (result.second.size() < 100) Output::vectorPrint(result.second);
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result =
      measureMethodPerformance(ITERATIONS, &Optimal::getAverages, o, nums, k);
  cout << "\tgetAverages (optimal), result = \t";
  if (result.second.size() < 100) Output::vectorPrint(result.second);
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int generateRandomInt(int min, int max) {
  return min + (rand() % (max - min + 1));
}
vector<int> generateRandomVector(int size, int min, int max) {
  vector<int> result(size);
  for (int i = 0; i < size; ++i) {
    result[i] = generateRandomInt(min, max);
  }
  return result;
}
int main() {
  vector<int> x;
  int k;
  x = {7, 4, 3, 9, 1, 8, 5, 2, 6};
  k = 3;
  test(x, k);
  x = {1000};
  k = 0;
  test(x, k);
  x = {8};
  k = 10000;
  test(x, k);
  x = generateRandomVector(500000, 0, 1000);
  k = generateRandomInt(0, 50000);
  test(x, k);
  return 0;
}