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
  bool isValidHIndex(vector<int>& citations, int n, int candidate) {
    int count = 0;
    for (int i = 0; i < n; i++) {
      if (citations[i] >= candidate) {
        count++;
        if (count >= candidate) return true;
      }
    }
    return false;
  }
  int hIndex(vector<int>& citations) {
    int n = citations.size();
    if (isValidHIndex(citations, n, n)) return n;
    int lowestInvalidCandidate = INT_MAX;
    int highestValidCandidate = 0;
    for (int i = 0; i < n; i++) {
      if (citations[i] > highestValidCandidate &&
          citations[i] < lowestInvalidCandidate) {
        if (isValidHIndex(citations, n, citations[i])) {
          highestValidCandidate = citations[i];
        } else {
          lowestInvalidCandidate = citations[i];
        }
      }
    }
    bool inLoop = false;
    while (isValidHIndex(citations, n, highestValidCandidate)) {
      highestValidCandidate++;
      inLoop = true;
    }
    if (inLoop) return --highestValidCandidate;
    return highestValidCandidate;
  }
};
class Optimal {
 public:
  int hIndex(vector<int>& citations) {
    int ans = 0;
    if (citations.size() == 1) {
      if (citations[0] == 0) {
        return 0;
      }
      return 1;
    }
    sort(citations.begin(), citations.end());
    for (int i = 0; i < citations.size(); i++) {
      if (citations[i] >= citations.size() - i) {
        return citations.size() - i;
      }
    }
    return 0;
  }
};
int test(vector<int>& citations) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nnums (size = " << citations.size() << ") = \t";
  // Output::vectorPrint(citations);
  cout << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::hIndex, s, citations);
  cout << "\tH-Index (mine), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::hIndex, o, citations);
  cout << "\tH-Index (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  return 0;
}
vector<int> generateRandomVector(int size) {
  vector<int> result = vector<int>(size);
  for (int i = 0; i < size; i++) {
    result[i] = rand() % 1000;
  }
  return result;
}
int main() {
  srand(time(nullptr));
  vector<int> x = {3, 0, 6, 1, 5};
  test(x);
  x = {1, 3, 1};
  test(x);
  x = {100};
  test(x);
  x = {4, 4, 0, 0};
  test(x);
  x = {1, 7, 9, 4};
  test(x);
  x = generateRandomVector(100);
  test(x);
  x = generateRandomVector(1000);
  test(x);
  x = generateRandomVector(5000);
  test(x);
  return 0;
}
