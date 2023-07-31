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
  bool wordPattern(const string &pattern, const string &s) const {
    vector<string> pattern2Word(26, "");
    map<string, char> word2Pattern;

    int pSize = pattern.length(), sSize = s.length(), wStart = 0;
    for (int i = 0; i < pSize; i++) {
      int wEnd = wStart;
      if (wEnd >= sSize) {
        return false;
      }
      while (wEnd < sSize && s[wEnd] != ' ') {
        wEnd++;
      }
      string currWord = s.substr(wStart, wEnd - wStart);
      if (pattern2Word[pattern[i] - 'a'] != "") {
        if (currWord != pattern2Word[pattern[i] - 'a']) {
          return false;
        }
      } else {
        if (word2Pattern.count(currWord) > 0 &&
            word2Pattern[currWord] != pattern[i]) {
          return false;
        }
        word2Pattern[currWord] != pattern[i];
        pattern2Word[pattern[i] - 'a'] = currWord;
      }

      wStart = wEnd + 1;
    }
    if (wStart < sSize) {
      return false;
    }
    return true;
  }
};
class Optimal {
 public:
  bool wordPattern(const string &pattern, const string &s) const {
    map<char, int> p2i;
    map<string, int> w2i;
    istringstream in(s);
    int i = 0, n = pattern.size();
    for (string word; in >> word; ++i) {
      if (i == n || p2i[pattern[i]] != w2i[word]) return false;
      p2i[pattern[i]] = w2i[word] = i + 1;
    }
    return i == n;
  }
};
int test(string pattern, string s) {
  Solution sol = Solution();
  Optimal o = Optimal();
  Timer time = Timer();

  cout << "\npattern (size = " << pattern.size() << ") = \t";
  cout << pattern << endl;
  cout << "s (size = " << s.size() << ") = \t";
  cout << s << endl;

  auto result = measureMethodPerformance(ITERATIONS, &Solution::wordPattern,
                                         sol, pattern, s);
  cout << "\twordPattern (mine), result = \t\t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::wordPattern, o,
                                    pattern, s);
  cout << "\twordPattern (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  string pattern, s;
  pattern = "jquery";
  s = "jquery";
  test(pattern, s);
  pattern = "aaa";
  s = "aa aa aa aa";
  test(pattern, s);
  pattern = "abba";
  s = "dog dog dog dog";
  test(pattern, s);
  pattern = "abba";
  s = "dog cat cat dog";
  test(pattern, s);
  pattern = "abba";
  s = "dog cat cat fish";
  test(pattern, s);
  pattern = "aaaa";
  s = "dog cat cat dog";
  test(pattern, s);
  return 0;
}