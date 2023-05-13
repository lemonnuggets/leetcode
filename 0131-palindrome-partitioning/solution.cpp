#include "../modules/index.h"
#define ITERATIONS 50
class Solution {
  map<string, vector<vector<string>>> seen;

 public:
  bool isPalindrome(string s) {
    for (int i = 0; i < s.size() / 2; i++) {
      int j = s.size() - 1 - i;
      if (s[i] != s[j]) return false;
    }
    return true;
  }
  vector<vector<string>> partition(string s) {
    if (s.size() == 0) return {};
    if (s.size() == 1) return {{s}};
    if (seen.count(s) > 0) return seen[s];
    vector<vector<string>> results;
    if (isPalindrome(s)) results.push_back({s});
    for (int i = 1; i < s.size(); i++) {
      string sub = s.substr(0, i);
      if (!isPalindrome(sub)) continue;
      string rest = s.substr(i);
      vector<vector<string>> rest_results = this->partition(rest);
      for (int j = 0; j < rest_results.size(); j++) {
        vector<string> result = rest_results[j];
        result.insert(result.begin(), sub);
        results.push_back(result);
      }
    }
    seen[s] = results;
    return results;
  }
};
class Optimal {
 public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> pars;
    vector<string> par;
    privPartition(s, 0, par, pars);
    return pars;
  }

 private:
  void privPartition(string& s, int start, vector<string>& par,
                     vector<vector<string>>& partitions) {
    int n = s.length();
    if (start == n) {
      partitions.push_back(par);
    } else {
      for (int i = start; i < n; i++) {
        if (isPalindrome(s, start, i)) {
          par.push_back(s.substr(start, i - start + 1));
          privPartition(s, i + 1, par, partitions);
          par.pop_back();
        }
      }
    }
  }

  bool isPalindrome(string& s, int l, int r) {
    while (l < r) {
      if (s[l++] != s[r--]) {
        return false;
      }
    }
    return true;
  }
};
int test(string x) {
  Solution s = Solution();
  Optimal o = Optimal();

  cout << "\nX (size = " << x.size() << ") = \t";
  cout << x << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::partition, s, x);
  cout << "\tPartitioned Palindromes (mine), result = \t";
  cout << "(";
  for (int i = 0; i < result.second.size(); i++) {
    Output::vectorPrint(result.second[i]);
    cout << ", ";
  }
  cout << ")" << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::partition, o, x);
  cout << "\tPartitioned Palindromes (optimal), result = \t";
  cout << "(";
  for (int i = 0; i < result.second.size(); i++) {
    Output::vectorPrint(result.second[i]);
    cout << ", ";
  }
  cout << ")" << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  string x;
  x = "aab";
  test(x);

  x = "a";
  test(x);

  x = "abacddcd";
  test(x);
  return 0;
}