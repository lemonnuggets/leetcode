#include "../modules/index.h"
#define ITERATIONS 1
static auto _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();
    int reachable = 0;
    int i = 0;
    while (i <= reachable) {
      reachable = max(reachable, i + nums[i]);
      if (reachable >= n - 1) return true;
      i++;
    }
    return false;
  }
};
class Optimal {
 public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();
    int reachable = 0;
    for (int i = 0; i <= reachable; i++) {
      reachable = max(reachable, i + nums[i]);
      if (reachable >= n - 1) return true;
    }
    return false;
  }
};

int test(vector<int>& nums) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nnums (size = " << nums.size() << ") = \t";
  Output::vectorPrint(nums);
  cout << endl;

  pair<double, bool> result =
      measureMethodPerformance(ITERATIONS, &Solution::canJump, s, nums);
  cout << "\tMax Profit (mine), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::canJump, o, nums);
  cout << "\tMax Profit (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  return 0;
}
vector<int> generateRandomVector(int size) {
  vector<int> result = vector<int>(size);
  for (int i = 0; i < size; i++) {
    result[i] = rand() % 100;
  }
  return result;
}
int main() {
  vector<int> x = {2, 3, 1, 1, 4};
  test(x);
  x = {3, 2, 1, 0, 4};
  test(x);
  x = {0};
  test(x);
  x = {8, 2, 4, 4, 4, 9, 5, 2, 5, 8, 8, 0, 8, 6, 9, 1, 1, 6, 3, 5, 1,
       2, 6, 6, 0, 4, 8, 6, 0, 3, 2, 8, 7, 6, 5, 1, 7, 0, 3, 4, 8, 3,
       5, 9, 0, 4, 0, 1, 0, 5, 9, 2, 0, 7, 0, 2, 1, 0, 8, 2, 5, 1, 2,
       3, 9, 7, 4, 7, 0, 0, 1, 8, 5, 6, 7, 5, 1, 9, 9, 3, 5, 0, 7, 5};
  test(x);
  // x = generateRandomVector(1000000);
  // test(x);
  return 0;
}
