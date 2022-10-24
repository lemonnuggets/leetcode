#include <bits/stdc++.h>
using namespace std;
class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.size() <= 0) return "";
    string prefix = strs[0];
    for (int i = 1; i < strs.size(); i++) {
      string str = strs[i];
      for (int j = 0; j < prefix.size(); j++) {
        if (str[j] != prefix[j]) {
          prefix = str.substr(0, j);
          break;
        }
      }
      if (prefix.size() <= 0) return prefix;
    }
    return prefix;
  }
};
int main() {
  Solution s = Solution();
  vector<string> ra1{"hello", "help", "heaven", "heathen"};
  vector<string> ra2{"flower", "flow", "flight"};
  vector<string> ra3{"dog", "racecar", "car"};
  // s.longestCommonPrefix(ra1);
  // s.longestCommonPrefix(ra2);
  // s.longestCommonPrefix(ra3);
  cout << s.longestCommonPrefix(ra1) << endl;
  cout << s.longestCommonPrefix(ra2) << endl;
  cout << s.longestCommonPrefix(ra3) << endl;
  return 0;
}