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
  bool canConstruct(const string &ransomNote, const string &magazine) const {
    int mCounts[26] = {0};
    for (char c : magazine) {
      mCounts[c - 'a']++;
    }
    for (char c : ransomNote) {
      mCounts[c - 'a']--;
      if (mCounts[c - 'a'] < 0) {
        return false;
      }
    }
    return true;
  }
};
class Optimal {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    int mCounts[26] = {0};
    for (char c : magazine) {
      mCounts[c - 'a']++;
    }
    for (char c : ransomNote) {
      mCounts[c - 'a']--;
      if (mCounts[c - 'a'] < 0) {
        return false;
      }
    }
    return true;
  }
};
int test(string ransomNote, string magazine) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nransomNote (size = " << ransomNote.size() << ") = \t";
  cout << ransomNote << endl;
  cout << "magazine (size = " << magazine.size() << ") = \t\t";
  cout << magazine << endl;

  auto result = measureMethodPerformance(ITERATIONS, &Solution::canConstruct, s,
                                         ransomNote, magazine);
  cout << "\tcanConstruct (mine), result = \t\t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::canConstruct, o,
                                    ransomNote, magazine);
  cout << "\tcanConstruct (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  string ransomNote, magazine;
  ransomNote = "a";
  magazine = "b";
  test(ransomNote, magazine);
  ransomNote = "aa";
  magazine = "ab";
  test(ransomNote, magazine);
  ransomNote = "aa";
  magazine = "aab";
  test(ransomNote, magazine);
  ransomNote =
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "a";
  magazine =
      "bbbbbbbbbbbbbbbaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
      "aaaaaa";
  test(ransomNote, magazine);
  return 0;
}