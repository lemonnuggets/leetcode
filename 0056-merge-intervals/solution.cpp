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
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() <= 1) {
      return intervals;
    }
    priority_queue<int> startingIndices;
    map<int, int> endIndices;
    for (auto interval : intervals) {
      startingIndices.emplace(-interval[0]);
      endIndices[interval[0]] = max(endIndices[interval[0]], interval[1]);
    }
    vector<vector<int>> res;
    int curr = -1;
    do {
      while (!startingIndices.empty() && -startingIndices.top() <= curr) {
        startingIndices.pop();
      }
      if (startingIndices.empty()) {
        break;
      }
      curr = -startingIndices.top();
      startingIndices.pop();
      int currStart = curr, currEnd = endIndices[curr];
      while (!startingIndices.empty() && -startingIndices.top() <= currEnd) {
        currEnd = max(currEnd, endIndices[-startingIndices.top()]);
        startingIndices.pop();
      }
      res.push_back({currStart, currEnd});

      curr = currEnd;
    } while (curr <= 1e4);
    return res;
  }
};
class Optimal {
 public:
  // from leetcode:
  // https://leetcode.com/problems/merge-intervals/solutions/482195/c-9-lines-99-run-time-easy-to-understand-solution/?envType=study-plan-v2&envId=top-interview-150
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() <= 1) return intervals;
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> output;
    output.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
      if (output.back()[1] >= intervals[i][0])
        output.back()[1] = max(output.back()[1], intervals[i][1]);
      else
        output.push_back(intervals[i]);
    }
    return output;
  }
};
int test(vector<vector<int>>& intervals) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nintervals (size = " << intervals.size() << ") = \t";
  if (intervals.size() < 100) {
    Output::vectorPrint(intervals);
  }
  cout << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::merge, s, intervals);
  cout << "\tmerge (mine), result = \t\t";
  if (result.second.size() < 100) {
    Output::vectorPrint(result.second);
  }
  cout << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::merge, o, intervals);
  cout << "\tmerge (optimal), result = \t";
  if (result.second.size() < 100) {
    Output::vectorPrint(result.second);
  }
  cout << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  vector<vector<int>> intervals;
  intervals = {{2, 3}, {4, 6}, {5, 7}, {3, 4}};
  test(intervals);
  intervals = {{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};
  test(intervals);
  intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  test(intervals);
  intervals = {{1, 4}, {4, 5}};
  test(intervals);
  return 0;
}