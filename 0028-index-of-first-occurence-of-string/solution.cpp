#include "../modules/index.h"
#define ITERATIONS 50
class Solution {
 public:
  int subStrMatch(string str1, int l, string str2) {
    int i = 0;
    while (i < str2.size()) {
      if (str1[i + l] != str2[i]) {
        return 0;
      }
      i++;
    }
    return 1;
  }
  int strStr(string haystack, string needle) {
    if (needle.size() > haystack.size()) {
      return -1;
    }
    for (int i = 0; i < haystack.size() - needle.size() + 1; i++) {
      if (subStrMatch(haystack, i, needle)) {
        return i;
      }
    }
    return -1;
  }
};
class Optimal {
 public:
  int subStrMatch(string str1, int l, string str2) {
    int i = 0;
    while (i < str2.size()) {
      if (str1[i + l] != str2[i]) {
        return 0;
      }
      i++;
    }
    return 1;
  }
  int strStr(string haystack, string needle) {
    if (needle.size() > haystack.size()) {
      return -1;
    }
    for (int i = 0; i < haystack.size() - needle.size() + 1; i++) {
      if (subStrMatch(haystack, i, needle)) {
        return i;
      }
    }
    return -1;
  }
};
int test(string haystack, string needle) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nHaystack (size = " << haystack.size() << ") = \t";
  cout << haystack << endl;

  cout << "\nNeedle (size = " << needle.size() << ") = \t";
  cout << needle << endl;

  auto result = measureMethodPerformance(ITERATIONS, &Solution::strStr, s,
                                         haystack, needle);
  cout << "\tStrStr (mine), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::strStr, o, haystack,
                                    needle);
  cout << "\tStrStr (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  string x, y;

  x = "sadbutsad";
  y = "sad";
  test(x, y);

  x = "leetcode";
  y = "leeto";
  test(x, y);

  x = "hello";
  y = "ll";
  test(x, y);

  x = "a";
  y = "a";
  test(x, y);

  x = "abb";
  y = "abaaa";
  test(x, y);

  x = "aaa";
  y = "aaaa";
  test(x, y);
  return 0;
}