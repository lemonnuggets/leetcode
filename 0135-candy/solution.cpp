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
  int indexOfLowestInRange(vector<int>& ratings, int start, int end) {
    int lowI = start;
    for (int i = start + 1; i < end; i++) {
      if (ratings[lowI] > ratings[i]) {
        lowI = i;
      }
    }
    return lowI;
  }
  int populateCandyPositive(vector<int>& ratings, vector<int>& candyPositive,
                            int start, int end) {
    if (end <= start) return 0;
    int lowI = indexOfLowestInRange(ratings, start, end);
    if (lowI - 1 >= start && ratings[lowI - 1] > ratings[lowI] &&
        candyPositive[lowI - 1] <= candyPositive[lowI]) {
      candyPositive[lowI - 1] = candyPositive[lowI] + 1;
    }
    if (lowI + 1 < end && ratings[lowI + 1] > ratings[lowI] &&
        candyPositive[lowI + 1] <= candyPositive[lowI]) {
      candyPositive[lowI + 1] = candyPositive[lowI] + 1;
    }
    int candiesFromLeft =
        populateCandyPositive(ratings, candyPositive, start, lowI);
    int candiesFromRight =
        populateCandyPositive(ratings, candyPositive, lowI + 1, end);
    return candiesFromLeft + candyPositive[lowI] + candiesFromRight;
  }
  int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candyPositive(n, 0);
    return n + populateCandyPositive(ratings, candyPositive, 0, n);
  }
};
class Optimal {
 public:
  int candy(vector<int>& ratings) {
    int n = ratings.size();
    int candy = n, i = 1;
    while (i < n) {
      if (ratings[i] == ratings[i - 1]) {
        i++;
        continue;
      }

      // For increasing slope
      int peak = 0;
      while (ratings[i] > ratings[i - 1]) {
        peak++;
        candy += peak;
        i++;
        if (i == n) return candy;
      }

      // For decreasing slope
      int valley = 0;
      while (i < n && ratings[i] < ratings[i - 1]) {
        valley++;
        candy += valley;
        i++;
      }
      candy -= min(peak, valley);  // Keep only the higher peak
    }
    return candy;
  }
};
int test(vector<int>& ratings) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nratings (size = " << ratings.size() << ") = \t";
  if (ratings.size() < 100) {
    Output::vectorPrint(ratings);
  }
  cout << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::candy, s, ratings);
  cout << "\tcandy (mine), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::candy, o, ratings);
  cout << "\tcandy (optimal), result = \t";
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
vector<int> getRandomVector(int n) {
  vector<int> v;
  for (int i = 0; i < n; i++) {
    v.push_back(rand() % n);
  }
  return v;
}
int main() {
  const int LIMIT = 2e4;
  vector<int> x;
  x = {7, 4, 8, 3, 2};
  test(x);
  x = {1, 0, 2};
  test(x);
  x = {1, 2, 2};
  test(x);
  x = getAscendingVector(LIMIT);
  test(x);
  x = getDescendingVector(LIMIT);
  test(x);
  x = getConstantVector(LIMIT);
  test(x);
  x = getRandomVector(LIMIT);
  test(x);
  return 0;
}