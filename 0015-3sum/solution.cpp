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
  vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    set<vector<int>> res;
    int i = 0, j = n - 1;
    while (i < j) {
      int x = -(nums[i] + nums[j]);
      vector<int>::iterator lo, hi;
      if (x < nums[i]) {
        lo = nums.begin();
        hi = nums.begin() + i;
        if (binary_search(lo, hi, x)) {
          res.insert({x, nums[i], nums[j]});
        }
      } else if (x <= nums[j]) {
        lo = nums.begin() + i + 1;
        hi = nums.begin() + j;
        if (binary_search(lo, hi, x)) {
          res.insert({nums[i], x, nums[j]});
        }
      } else {
        lo = nums.begin() + j + 1;
        hi = nums.end();
        if (binary_search(lo, hi, x)) {
          res.insert({nums[i], nums[j], x});
        }
      }
      do {
        j--;
      } while (nums[j] == nums[j + 1] && j > 0);
      if (i >= j) {
        do {
          i++;
        } while (nums[i] == nums[i - 1] && i < n - 1);
        j = n - 1;
      }
    }
    vector<vector<int>> v(res.begin(), res.end());
    return v;
  }
};
class Optimal {
 public:
  vector<vector<int>> threeSum(vector<int>& num) {
    vector<vector<int>> res;

    std::sort(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++) {
      int target = -num[i];
      int front = i + 1;
      int back = num.size() - 1;

      while (front < back) {
        int sum = num[front] + num[back];

        // Finding answer which start from number num[i]
        if (sum < target)
          front++;

        else if (sum > target)
          back--;

        else {
          vector<int> triplet = {num[i], num[front], num[back]};
          res.push_back(triplet);

          // Processing duplicates of Number 2
          // Rolling the front pointer to the next different number forwards
          while (front < back && num[front] == triplet[1]) front++;

          // Processing duplicates of Number 3
          // Rolling the back pointer to the next different number backwards
          while (front < back && num[back] == triplet[2]) back--;
        }
      }

      // Processing duplicates of Number 1
      while (i + 1 < num.size() && num[i + 1] == num[i]) i++;
    }

    return res;
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

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::threeSum, s, nums);
  cout << "\tthreeSum (mine), result = \t";
  if (result.second.size()) {
    Output::vectorPrint(result.second);
  }
  cout << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::threeSum, o, nums);
  cout << "\tthreeSum (optimal), result = \t";
  if (result.second.size()) {
    Output::vectorPrint(result.second);
  }
  cout << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  vector<int> x;
  x = {0, 0, 0};
  test(x);
  x = {-1, 0, 1, 2, -1, -4};
  test(x);
  x = {0, 1, 1};
  test(x);
  return 0;
}