#include "../modules/index.h"
#define ITERATIONS 50
class Solution {
 public:
  string getRange(int rangeStart, int rangeEnd) {
    if (rangeStart == rangeEnd) return to_string(rangeEnd);
    return to_string(rangeStart) + "->" + to_string(rangeEnd);
  }
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ranges;
    if (nums.size() == 0) return ranges;

    int rangeStart = nums[0], rangeEnd = nums[0];
    for (long num : nums) {
      if (num - rangeEnd <= 1) {
        rangeEnd = num;
        continue;
      }

      ranges.push_back(getRange(rangeStart, rangeEnd));
      rangeStart = rangeEnd = num;
    }

    ranges.push_back(getRange(rangeStart, rangeEnd));
    return ranges;
  }
};
class Optimal {
 public:
  string getRange(long rangeStart, long rangeEnd) {
    if (rangeStart == rangeEnd) return to_string(rangeEnd);
    return to_string(rangeStart) + "->" + to_string(rangeEnd);
  }
  vector<string> summaryRanges(vector<int>& nums) {
    vector<string> ranges;
    if (nums.size() == 0) return ranges;

    long rangeStart = nums[0], rangeEnd = nums[0];
    for (long num : nums) {
      if (num - rangeEnd <= 1) {
        rangeEnd = num;
        continue;
      }

      ranges.push_back(getRange(rangeStart, rangeEnd));
      rangeStart = rangeEnd = num;
    }

    ranges.push_back(getRange(rangeStart, rangeEnd));
    return ranges;
  }
};
int test(vector<int>& nums) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nnums (size = " << nums.size() << ") = \t";
  Output::vectorPrint(nums);
  cout << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::summaryRanges, s, nums);
  cout << "\tSummary Ranges (mine), result = \t";
  Output::vectorPrint(result.second);
  cout << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result =
      measureMethodPerformance(ITERATIONS, &Optimal::summaryRanges, o, nums);
  cout << "\tSummary Ranges (optimal), result = \t";
  Output::vectorPrint(result.second);
  cout << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  vector<int> x = {0, 1, 2, 4, 5, 7};
  test(x);

  x = {0, 2, 3, 4, 6, 8, 9};
  test(x);

  x = {-2147483648, -2147483647, 2147483647};
  test(x);
  return 0;
}