#include "../modules/index.h"
#define ITERATIONS 50
class Solution {
 public:
  unordered_map<char, int> getFingerprint(string s) {
    unordered_map<char, int> fingerprint;
    for (int i = 0; i < s.size(); i++) {
      if (fingerprint[s[i]] <= 0) {
        fingerprint[s[i]] = 1;
      } else {
        fingerprint[s[i]]++;
      }
    }
    return fingerprint;
  }
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<unordered_map<char, int>> fingerprints;
    vector<vector<string>> results;
    for (auto it = strs.begin(); it != strs.end(); it++) {
      unordered_map<char, int> fingerprint = getFingerprint(*it);
      bool found = false;
      for (int i = 0; i < fingerprints.size(); i++) {
        if (fingerprints[i] == fingerprint) {
          found = true;
          results[i].push_back(*it);
        }
      }
      if (!found) {
        vector<string> v;
        v.push_back(*it);
        results.push_back(v);
        fingerprints.push_back(fingerprint);
      }
    }
    return results;
  }
};
class Optimal {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    vector<vector<string>> ans;
    for (int i = 0; i < strs.size(); i++) {
      string t = strs[i];
      sort(t.begin(), t.end());
      mp[t].push_back(strs[i]);
    }
    for (auto it = mp.begin(); it != mp.end(); it++) {
      ans.push_back(it->second);
    }
    return ans;
  }
};

int test(vector<string>& x) {
  Solution s = Solution();
  Optimal o = Optimal();

  cout << "\nX (size = " << x.size() << ") = \t";
  Output::vectorPrint(x);
  cout << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::groupAnagrams, s, x);

  cout << "\tGroup Anagrams (mine), result = \t";
  cout << "(";
  for (int i = 0; i < result.second.size(); i++) {
    Output::vectorPrint(result.second[i]);
    cout << ", ";
  }
  cout << ")" << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::groupAnagrams, o, x);
  cout << "\tGroup Anagrams (optimal), result = \t";
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
  vector<string> x;
  x = {"eat", "tea", "tan", "ate", "nat", "bat"};
  test(x);

  x = {""};
  test(x);

  x = {"a"};
  test(x);
  return 0;
}