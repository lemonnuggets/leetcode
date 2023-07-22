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
  int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if (n <= 1) return n;
    map<char, int> counts;
    int i = 0, j = 0, longest = INT_MIN;
    counts[s[j++]] = 1;

    while (i < j && j < n) {
      counts[s[j++]]++;
      while (counts[s[j - 1]] > 1) {
        counts[s[i++]]--;
      }
      longest = max(longest, j - i);
    }
    return longest;
  }
};
class Optimal {
 public:
  int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if (n <= 1) return n;
    map<char, int> counts;
    int i = 0, j = 0, longest = INT_MIN;
    counts[s[j++]] = 1;

    while (i < j && j < n) {
      counts[s[j++]]++;
      while (counts[s[j - 1]] > 1) {
        counts[s[i++]]--;
      }
      longest = max(longest, j - i);
    }
    return longest;
  }
};
int test(string argument) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nArgument (size = " << argument.size() << ") = \t";
  cout << argument << endl;

  auto result = measureMethodPerformance(
      ITERATIONS, &Solution::lengthOfLongestSubstring, s, argument);
  cout << "\tlengthOfLongestSubstring (mine), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(
      ITERATIONS, &Optimal::lengthOfLongestSubstring, o, argument);
  cout << "\tlengthOfLongestSubstring (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  string x;
  x = "aa";
  test(x);
  x = " ";
  test(x);
  x = "abcabcbb";
  test(x);
  x = "bbbbb";
  test(x);
  x = "pwwkew";
  test(x);
  return 0;
}