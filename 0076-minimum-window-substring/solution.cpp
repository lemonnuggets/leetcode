#include "../modules/index.h"
#define ITERATIONS 50
static auto _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
const int NUM_ALPHA = 52;
class Solution {
 public:
  int idx(char ch) {
    if (ch >= 'a' && ch <= 'z') {
      return ch - 'a';
    }
    if (ch >= 'A' && ch <= 'Z') {
      return ch - 'A' + ('z' - 'a' + 1);
    }
    return -1;
  }
  string minWindow(string s, string t) {
    int sSize = s.size(), tSize = t.size();
    if (tSize > sSize) {
      return "";
    }
    vector<int> tCounts(NUM_ALPHA, 0);
    for (int i = 0; i < tSize; i++) {
      char c = t[i];
      int x = idx(c);
      tCounts[idx(t[i])]++;
    }

    vector<int> sCounts(NUM_ALPHA, 0);
    for (int i = 0; i < sSize; i++) {
      sCounts[idx(s[i])]++;
    }
    for (int i = 0; i < NUM_ALPHA; i++) {
      if (tCounts[i] > sCounts[i]) {
        return "";
      }
    }
    int i = 0, j = sSize - 1;
    int minI = i, minJ = j;
    while (sCounts[idx(s[j])] > tCounts[idx(s[j])]) {
      sCounts[idx(s[j])]--;
      j--;
    }
    if (minJ - minI > j - i) {
      minI = i;
      minJ = j;
    }
    while (i < j && j < sSize) {
      sCounts[idx(s[i])]--;
      if (sCounts[idx(s[i])] < tCounts[idx(s[i])]) {
        while (j + 1 < sSize && sCounts[idx(s[i])] < tCounts[idx(s[i])]) {
          j++;
          sCounts[idx(s[j])]++;
        }
        if (sCounts[idx(s[i])] < tCounts[idx(s[i])]) {
          break;
        }
      } else {
        while (sCounts[idx(s[j])] > tCounts[idx(s[j])]) {
          sCounts[idx(s[j])]--;
          j--;
        }
      }
      i++;
      if (minJ - minI > j - i) {
        minI = i;
        minJ = j;
      }
    }
    return s.substr(minI, minJ - minI + 1);
  }
};
class Optimal {
  // from leetcode sample codes based on perf
 public:
  string minWindow(string s, string t) {
    vector<int> map(128, 0);
    // Create a map for storing all chars in t and their number of existents
    for (char c : t) {
      map[c]++;
    }

    int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
    while (end < s.size()) {
      // This mean we compare map[s[end]]-- > 0 and then increase end
      //
      if (map[s[end++]]-- > 0) {
        counter--;
      }
      while (counter == 0) {
        if (end - begin < d) {
          head = begin;
          d = end - head;
        }
        if (map[s[begin++]]++ == 0) {
          counter++;
        }
      }
    }
    return d == INT_MAX ? "" : s.substr(head, d);
  }
};
int test(string str1, string str2) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nstr1 (size = " << str1.size() << ") = \t";
  if (str1.size() < 100) {
    cout << str1;
  }
  cout << endl;
  cout << "str2 (size = " << str2.size() << ") = \t";
  if (str2.size() < 100) {
    cout << str2;
  }
  cout << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::minWindow, s, str1, str2);
  cout << "\tminWindow (mine), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result =
      measureMethodPerformance(ITERATIONS, &Optimal::minWindow, o, str1, str2);
  cout << "\tminWindow (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  string s, t;
  s = "cabwefgewcwaefgcf";
  t = "cae";
  test(s, t);
  s = "a";
  t = "b";
  test(s, t);
  s = "ab";
  t = "a";
  test(s, t);
  s = "cfabeca";
  t = "cae";
  test(s, t);
  s = "abc";
  t = "cba";
  test(s, t);
  s = "ADOBECODEBANC";
  t = "ABC";
  test(s, t);
  s = "a";
  t = "a";
  test(s, t);
  s = "a";
  t = "aa";
  test(s, t);
  return 0;
}
