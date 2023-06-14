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
  int removeDuplicates(vector<int>& nums) {
    int ptr1 = 1, ptr2 = 1, n = nums.size(), prev = nums[0], timesSeen = 1;
    while (ptr2 < n) {
      nums[ptr1] = nums[ptr2];
      if (prev != nums[ptr1]) {
        prev = nums[ptr1];
        timesSeen = 1;
        ptr1++;
        ptr2++;
        continue;
      }

      timesSeen++;
      if (timesSeen > 2) {
        ptr2++;
        continue;
      }

      ptr1++;
      ptr2++;
    }
    return ptr1;
  }
};
class Optimal {
 public:
  int removeDuplicates(vector<int>& nums) {
    int count = 1, i = 1, j = 1;
    int n = nums.size();
    while (i < n) {
      if (nums[i] == nums[i - 1]) {
        if (count < 2) {
          count++;
          nums[j++] = nums[i];
        }
      } else {
        count = 1;
        nums[j++] = nums[i];
      }
      i++;
    }
    return j;
  }
};
int test(vector<int>& nums) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nNums (size = " << nums.size() << ") = \t";
  // Output::vectorPrint(nums);
  cout << endl;

  vector<int> numsCopy = nums;
  double totalTime = 0.0;
  int result;

  for (int i = 0; i < ITERATIONS; i++) {
    t.startClock();
    result = s.removeDuplicates(numsCopy);
    numsCopy = nums;
    double elapsed = static_cast<double>(t.stopClock());
    totalTime += elapsed;
  }
  totalTime = 0.0;
  for (int i = 0; i < ITERATIONS; i++) {
    t.startClock();
    result = s.removeDuplicates(numsCopy);
    numsCopy = nums;
    double elapsed = static_cast<double>(t.stopClock());
    totalTime += elapsed;
  }

  result = s.removeDuplicates(numsCopy);
  cout << "\tRemove Element (mine), result = \t";
  cout << result << endl;
  cout << "\t\t\t\tNums (size = " << nums.size() << ")\t";
  // Output::vectorPrint(numsCopy);
  cout << "\n\t\t\t\tTime Taken: " << totalTime / ITERATIONS << endl;

  numsCopy = nums;
  for (int i = 0; i < ITERATIONS; i++) {
    t.startClock();
    result = o.removeDuplicates(numsCopy);
    numsCopy = nums;
    double elapsed = static_cast<double>(t.stopClock());
    totalTime += elapsed;
  }
  totalTime = 0.0;
  for (int i = 0; i < ITERATIONS; i++) {
    t.startClock();
    result = o.removeDuplicates(numsCopy);
    numsCopy = nums;
    double elapsed = static_cast<double>(t.stopClock());
    totalTime += elapsed;
  }

  result = o.removeDuplicates(numsCopy);
  cout << "\tRemove Element (optimal), result = \t";
  cout << result << endl;
  cout << "\t\t\t\tNums (size = " << nums.size() << ")\t";
  // Output::vectorPrint(numsCopy);
  cout << "\n\t\t\t\tTime Taken: " << totalTime / ITERATIONS << endl;
  return 0;
}
vector<int> getRandomSortedVector(int size) {
  vector<int> nums;
  int current = 0;
  int times = 0;
  while (nums.size() < size) {
    if (times <= 0) {
      current += rand() % 5;
      times = rand() % 5 + 1;
    }
    nums.push_back(current);
    times--;
  }
  return nums;
}
int main() {
  vector<int> nums = {1, 1, 1, 2, 2, 3};
  test(nums);
  nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
  test(nums);
  nums = getRandomSortedVector(100);
  test(nums);
  nums = getRandomSortedVector(1000);
  test(nums);
  return 0;
}