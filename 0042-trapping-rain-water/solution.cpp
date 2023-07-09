#include "../modules/index.h"
#define ITERATIONS 200
static auto _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class Solution {
 public:
  int trap(vector<int>& height) {
    int n = height.size(), trapped = 0, maybeTrapped = 0, maxInBasin = 0;
    for (int i = 0; i < n; i++) {
      if (height[i] >= maxInBasin) {
        maxInBasin = height[i];
        trapped += maybeTrapped;
        maybeTrapped = 0;
        continue;
      }
      maybeTrapped += maxInBasin - height[i];
    }
    int peak = maxInBasin;
    maybeTrapped = 0, maxInBasin = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (height[i] >= peak) {
        break;
      }
      if (height[i] >= maxInBasin) {
        maxInBasin = height[i];
        continue;
      }
      trapped += maxInBasin - height[i];
    }
    return trapped;
  }
};
class Optimal {
 public:
  int trap(vector<int>& height) {
    int n = height.size();
    int left = 0;
    int right = n - 1;
    int res = 0;
    int maxLeft = 0, maxRight = 0;
    while (left <= right) {
      if (height[left] <= height[right]) {
        if (height[left] >= maxLeft)
          maxLeft = height[left];
        else
          res += maxLeft - height[left];
        left++;
      } else {
        if (height[right] >= maxRight)
          maxRight = height[right];
        else
          res += maxRight - height[right];
        right--;
      }
    }
    return res;
  }
};
int test(vector<int>& height) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nheight (size = " << height.size() << ") = \t";
  if (height.size() < 100) {
    Output::vectorPrint(height);
  }
  cout << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::trap, s, height);
  cout << "\ttrap (mine), result = \t\t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::trap, o, height);
  cout << "\ttrap (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
vector<int> getAscendingVector(int n) {
  vector<int> v;
  for (int i = 0; i < n; i++) {
    v.push_back(i);
  }
  return v;
}
vector<int> getDescendingVector(int n) {
  vector<int> v;
  for (int i = n - 1; i >= 0; i--) {
    v.push_back(i);
  }
  return v;
}
vector<int> getConstantVector(int n) {
  vector<int> v;
  for (int i = 0; i < n; i++) {
    v.push_back(0);
  }
  return v;
}
vector<int> getRandomVector(int n, int x) {
  vector<int> v;
  for (int i = 0; i < n; i++) {
    v.push_back(rand() % x);
  }
  return v;
}
int main() {
  const int SIZE_LIMIT = 2e4, VAL_LIMIT = 1e5;
  vector<int> height;
  height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  test(height);
  height = {4, 2, 0, 3, 2, 5};
  test(height);
  height = getAscendingVector(SIZE_LIMIT);
  test(height);
  height = getDescendingVector(SIZE_LIMIT);
  test(height);
  height = getConstantVector(SIZE_LIMIT);
  test(height);
  height = getRandomVector(SIZE_LIMIT, VAL_LIMIT);
  test(height);
  return 0;
}