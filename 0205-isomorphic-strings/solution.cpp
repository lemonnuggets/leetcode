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
  bool canMapTo(const string &s, const string &t) const {
    int n = s.size();
    if (n != t.size()) return false;
    // int mapping[128] = {-1};
    vector<int> mapping(128, -1);
    for (int i = 0; i < n; i++) {
      if (mapping[s[i]] < 0) {
        mapping[s[i]] = (int)t[i];
        continue;
      }

      if (mapping[s[i]] != (int)t[i]) {
        return false;
      }
    }
    return true;
  }
  bool isIsomorphic(const string &s, const string &t) const {
    return canMapTo(s, t) && canMapTo(t, s);
  }
};
class Optimal {
 public:
  bool canMapTo(const string &s, const string &t) const {
    int n = s.size();
    if (n != t.size()) return false;
    // int mapping[128] = {-1};
    vector<int> mapping(128, -1);
    for (int i = 0; i < n; i++) {
      if (mapping[s[i]] < 0) {
        mapping[s[i]] = (int)t[i];
        continue;
      }

      if (mapping[s[i]] != (int)t[i]) {
        return false;
      }
    }
    return true;
  }
  bool isIsomorphic(const string &s, const string &t) const {
    return canMapTo(s, t) && canMapTo(t, s);
  }
};
int test(string s, string t) {
  Solution sol = Solution();
  Optimal o = Optimal();
  Timer time = Timer();

  cout << "\ns (size = " << s.size() << ") = \t";
  cout << s << endl;
  cout << "t (size = " << t.size() << ") = \t";
  cout << t << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::isIsomorphic, sol, s, t);
  cout << "\tisIsomorphic (mine), result = \t\t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result =
      measureMethodPerformance(ITERATIONS, &Optimal::isIsomorphic, o, s, t);
  cout << "\tisIsomorphic (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  string s, t;
  s = "badc";
  t = "baba";
  test(s, t);
  s = "paper";
  t = "title";
  test(s, t);
  s = "egg";
  t = "add";
  test(s, t);
  s = "foo";
  t = "bar";
  test(s, t);
  return 0;
}