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
  void reverse(vector<int>& nums, int from, int till) {
    int i = from, j = till;
    while (i < j) {
      swap(nums[i++], nums[j--]);
    }
  }
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    int _k = k % n;
    reverse(nums, 0, n - 1);
    reverse(nums, 0, _k - 1);
    reverse(nums, _k, n - 1);
  }
};
class Optimal {  // not better than mine :(
  using iterator = vector<int>::iterator;

  void reverse(iterator first, iterator last) {
    for (; first != last && next(first) != last; ++first, --last) {
      swap(*first, *prev(last));
    }
  }

 public:
  void rotate(vector<int>& nums, int k) {
    auto const n = static_cast<int>(nums.size());
    k = k % n;
    if (k == 0) {
      return;
    }

    k = n - k;
    reverse(begin(nums), next(begin(nums), k));
    reverse(next(begin(nums), k), end(nums));
    reverse(begin(nums), end(nums));
  }
};
int test(vector<int>& nums, int k) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nNums (size = " << nums.size() << ") = \t";
  // Output::vectorPrint(nums);
  cout << endl;

  vector<int> numsCopy = nums;
  double totalTime = 0.0;

  for (int i = 0; i < ITERATIONS; i++) {
    t.startClock();
    s.rotate(numsCopy, k);
    numsCopy = nums;
    double elapsed = static_cast<double>(t.stopClock());
    totalTime += elapsed;
  }
  totalTime = 0.0;
  for (int i = 0; i < ITERATIONS; i++) {
    t.startClock();
    s.rotate(numsCopy, k);
    numsCopy = nums;
    double elapsed = static_cast<double>(t.stopClock());
    totalTime += elapsed;
  }

  s.rotate(numsCopy, k);
  cout << "\tRotate (mine), result = \t";
  // Output::vectorPrint(numsCopy);
  cout << "\n\t\t\t\tTime Taken: " << totalTime / ITERATIONS << endl;

  numsCopy = nums;
  for (int i = 0; i < ITERATIONS; i++) {
    t.startClock();
    o.rotate(numsCopy, k);
    numsCopy = nums;
    double elapsed = static_cast<double>(t.stopClock());
    totalTime += elapsed;
  }
  totalTime = 0.0;
  for (int i = 0; i < ITERATIONS; i++) {
    t.startClock();
    o.rotate(numsCopy, k);
    numsCopy = nums;
    double elapsed = static_cast<double>(t.stopClock());
    totalTime += elapsed;
  }

  o.rotate(numsCopy, k);
  cout << "\tRotate (optimal), result = \t";
  // Output::vectorPrint(numsCopy);
  cout << "\n\t\t\t\tTime Taken: " << totalTime / ITERATIONS << endl;
  return 0;
}
int getRand(int min, int max) { return min + rand() % (max - min + 1); }
vector<int> getRandVector(int size, int min, int max) {
  vector<int> x(size);
  for (int i = 0; i < size; i++) {
    x[i] = getRand(min, max);
  }
  return x;
}
int main() {
  srand(time(nullptr));
  vector<int> x = {1, 2, 3, 4, 5, 6, 7};
  int k = 3;
  test(x, k);
  x = {-1, -100, 3, 99};
  k = 2;
  test(x, k);
  x = getRandVector(100000, -100000, 100000);
  k = getRand(0, 100000);
  test(x, k);
  x = getRandVector(100000, -100000, 100000);
  k = getRand(0, 100000);
  test(x, k);
  return 0;
}