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
  bool isAnagram(const string &s, const string &t) const {
    int counts[26] = {0};
    int sSize = s.size();
    if (t.size() != sSize) {
      return false;
    }
    for (int i = 0; i < sSize; i++) {
      counts[s[i] - 'a']++;
    }
    for (int i = 0; i < sSize; i++) {
      counts[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
      if (counts[i] != 0) {
        return false;
      }
    }
    return true;
  }
};
class Optimal {
 public:
  bool isAnagram(const string &s, const string &t) const { return true; }
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
      measureMethodPerformance(ITERATIONS, &Solution::isAnagram, sol, s, t);
  cout << "\tisAnagram (mine), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::isAnagram, o, s, t);
  cout << "\tisAnagram (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  string s, t;
  s = "anagram";
  t = "nagaram";
  test(s, t);
  s = "car";
  t = "rat";
  test(s, t);
  return 0;
}