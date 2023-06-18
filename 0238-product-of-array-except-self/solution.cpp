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
  vector<int> productExceptSelf(vector<int> nums) {
    int n = nums.size();
    int currProduct = 1;
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
      result[i] = currProduct;
      currProduct *= nums[i];
    }
    currProduct = 1;
    for (int i = n - 2; i >= 0; i--) {
      currProduct *= nums[i + 1];
      result[i] *= currProduct;
    }
    return result;
  }
};
class Optimal {
 public:
  vector<int> productExceptSelf(vector<int> nums) {
    int n = nums.size();
    vector<int> result(n, 1);
    // instead of using currProduct to keep track of
    // product, just initializes result array to one
    // and each element equal to prev element times
    // corresponding element from nums
    for (int i = 0; i < n - 1; i++) {
      result[i + 1] = nums[i] * result[i];
    }
    int currProduct = 1;
    for (int i = n - 2; i >= 0; i--) {
      currProduct *= nums[i + 1];
      result[i] *= currProduct;
    }
    return result;
  }
};
int test(vector<int>& nums) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nnums (size = " << nums.size() << ") = \t";
  Output::vectorPrint(nums);
  cout << endl;

  auto result = measureMethodPerformance(ITERATIONS,
                                         &Solution::productExceptSelf, s, nums);
  cout << "\tproductExceptSelf (mine), result = \t";
  Output::vectorPrint(result.second);
  cout << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::productExceptSelf, o,
                                    nums);
  cout << "\tproductExceptSelf (optimal), result = \t";
  Output::vectorPrint(result.second);
  cout << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  vector<int> x = {1, 2, 3, 4};
  test(x);
  x = {-1, 1, 0, -3, 3};
  test(x);
  return 0;
}