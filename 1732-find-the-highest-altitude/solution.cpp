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
  int largestAltitude(vector<int>& gain) {
    int currAltitude = 0;
    int highestAltitude = 0;
    int n = gain.size();
    for (int i = 0; i < n; ++i) {
      currAltitude += gain[i];
      highestAltitude = max(currAltitude, highestAltitude);
    }
    return highestAltitude;
  }
};
class Optimal {
 public:
  int largestAltitude(vector<int>& gain) {
    int currAltitude = 0;
    int highestAltitude = 0;
    int n = gain.size();
    for (int i = 0; i < n; ++i) {
      currAltitude += gain[i];
      highestAltitude = max(currAltitude, highestAltitude);
    }
    return highestAltitude;
  }
};
int test(vector<int>& gain) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\ngain (size = " << gain.size() << ") = \t";
  Output::vectorPrint(gain);
  cout << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::largestAltitude, s, gain);
  cout << "\tlargestAltitude (mine), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result =
      measureMethodPerformance(ITERATIONS, &Optimal::largestAltitude, o, gain);
  cout << "\tlargestAltitude (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  vector<int> x;
  x = {-5, 1, 5, 0, -7};
  test(x);
  x = {-4, -3, -2, -1, 4, 3, 2};
  test(x);
  return 0;
}