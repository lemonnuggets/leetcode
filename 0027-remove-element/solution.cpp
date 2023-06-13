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
  int removeElement(vector<int>& nums, int val) {
    int k = nums.size();
    while (k > 0 && nums[k - 1] == val) {
      k--;
    }
    for (int i = 0; i < k; i++) {
      if (nums[i] != val) continue;
      nums[i] ^= nums[k - 1];
      nums[k - 1] ^= nums[i];
      nums[i] ^= nums[k - 1];
      // swap(nums[i], nums[--k]);
      while (k > 0 && nums[k - 1] == val) {
        k--;
      }
    }
    return k;
  }
};
class Optimal {
 public:
  int removeElement(vector<int>& nums, int val) {
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
      // no need to swap. just keep track of the count of non-val elements
      // and copy them to the front of the array
      if (nums[i] != val) nums[cnt++] = nums[i];
    }
    return cnt;
  }
};
int test(vector<int>& nums, int val) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nNums (size = " << nums.size() << ") = \t";
  Output::vectorPrint(nums);
  cout << "\nVal = \t\t\t" << val << endl;

  vector<int> numsCopy = nums;
  double totalTime = 0.0;
  int result;

  for (int i = 0; i < ITERATIONS; i++) {
    t.startClock();
    result = s.removeElement(numsCopy, val);
    numsCopy = nums;
    double elapsed = static_cast<double>(t.stopClock());
    totalTime += elapsed;
  }
  totalTime = 0.0;
  for (int i = 0; i < ITERATIONS; i++) {
    t.startClock();
    result = s.removeElement(numsCopy, val);
    numsCopy = nums;
    double elapsed = static_cast<double>(t.stopClock());
    totalTime += elapsed;
  }

  result = s.removeElement(numsCopy, val);
  cout << "\tRemove Element (mine), result = \t";
  cout << result << endl;
  cout << "\t\t\t\tNums (size = " << nums.size() << ") = \t";
  Output::vectorPrint(numsCopy);
  cout << "\n\t\t\t\tTime Taken: " << totalTime / ITERATIONS << endl;

  numsCopy = nums;
  for (int i = 0; i < ITERATIONS; i++) {
    t.startClock();
    result = o.removeElement(numsCopy, val);
    numsCopy = nums;
    double elapsed = static_cast<double>(t.stopClock());
    totalTime += elapsed;
  }
  totalTime = 0.0;
  for (int i = 0; i < ITERATIONS; i++) {
    t.startClock();
    result = o.removeElement(numsCopy, val);
    numsCopy = nums;
    double elapsed = static_cast<double>(t.stopClock());
    totalTime += elapsed;
  }

  result = o.removeElement(numsCopy, val);
  cout << "\tRemove Element (optimal), result = \t";
  cout << result << endl;
  cout << "\t\t\t\tNums (size = " << nums.size() << ") = \t";
  Output::vectorPrint(numsCopy);
  cout << "\n\t\t\t\tTime Taken: " << totalTime / ITERATIONS << endl;
  return 0;
}
int main() {
  vector<int> nums = {3, 2, 2, 3};
  int val = 3;
  test(nums, val);
  nums = {0, 1, 2, 2, 3, 0, 4, 2};
  val = 2;
  test(nums, val);
  nums = {0, 4, 4, 0, 4, 4, 4, 0, 2};
  val = 4;
  test(nums, val);
  nums = {4, 2, 0, 2, 2, 1, 4, 4, 1, 4, 3, 2};
  val = 4;
  test(nums, val);
  return 0;
}