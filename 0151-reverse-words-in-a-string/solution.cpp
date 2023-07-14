#include "../modules/index.h"
#define ITERATIONS 1000
static auto _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class Solution {
 public:
  void fixSpaces(string &str) {
    int n = str.size(), i = 0, j = 0;
    while (str[j] == ' ') {
      j++;
    }
    while (j < n) {
      str[i] = str[j];
      i++, j++;
      while (str[j] == ' ' && str[j - 1] == ' ') {
        j++;
      }
    }
    int k = 0;
    if (str[n - 1] == ' ') {
      k = 1;
    }
    str.resize(n - (k + j - i));
  }
  void reverse(string &str, int start, int end) {
    int i = start, j = end;
    char c;
    while (i < j) {
      c = str[i];
      str[i] = str[j];
      str[j] = c;
      i++, j--;
    }
  }
  string reverseWords(string s) {
    string str = s;
    fixSpaces(str);
    int n = str.size();
    reverse(str, 0, n - 1);
    int wStart = 0, wEnd = 0;
    while (wEnd < n - 1) {
      while (wEnd < n - 1 && str[wEnd + 1] != ' ') {
        wEnd++;
      }
      reverse(str, wStart, wEnd);
      wEnd += 2;
      wStart = wEnd;
    }
    return str;
  }
};
class Optimal {
 public:
  string reverseWords(string s) {
    vector<string> v;
    string str = "";
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == ' ' && str.length() > 0) {
        v.push_back(str);
        str.clear();
      } else if (s[i] != ' ') {
        str += s[i];
        if (i == s.length() - 1) {
          v.push_back(str);
        }
      }
    }
    str.clear();
    reverse(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
      str += v[i];
      if (i != v.size() - 1) str += " ";
    }
    return str;
  }
};
int test(string argument) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nArgument (size = " << argument.size() << ") = \t";
  cout << argument << endl;

  auto result = measureMethodPerformance(ITERATIONS, &Solution::reverseWords, s,
                                         argument);
  cout << "\treverseWords (mine), result = \t\t";
  cout << "'" << result.second << "'" << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result =
      measureMethodPerformance(ITERATIONS, &Optimal::reverseWords, o, argument);
  cout << "\treverseWords (optimal), result = \t";
  cout << "'" << result.second << "'" << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  string x;
  x = "F R  I   E    N     D      S      ";
  test(x);
  x = "the sky is blue";
  test(x);
  x = " the   ";
  test(x);
  x = "  hello world  ";
  test(x);
  x = "a good   example";
  test(x);
  x = "F R  I   E    N     D      S      the sky is blue the     hello world  "
      "a good   example";
  test(x);
  return 0;
}