#include <bits/stdc++.h>
using namespace std;
// used inefficent data structure (map, compared to 2D array)
class Solution {
 public:
  int romanToInt(string s) {
    unordered_map<char, int> mapping{{'I', 1},   {'V', 5},   {'X', 10},
                                     {'L', 50},  {'C', 100}, {'D', 500},
                                     {'M', 1000}};
    int value = 0;
    for (int i = 0; i < s.size(); i++) {
      cout << s[i] << "\t";
      auto match = mapping.find(s[i]);
      if (match != mapping.end()) {
        int curVal = match->second;
        int sign = 1;
        if (i + 1 < s.size()) {
          auto nextMatch = mapping.find(s[i + 1]);
          if (nextMatch != mapping.end()) {
            int nextVal = nextMatch->second;
            if (nextVal > curVal) sign = -1;
          } else {
            cout << "\t" << s[i + 1] << " doesn't have a match";
          }
        }
        value += sign * curVal;
      } else {
        cout << "\t" << s[i] << " doesn't have a match";
      }
    }
    return value;
  }
};
int main(int argc, char const *argv[]) {
  Solution s = Solution();
  cout << s.romanToInt("III") << endl;
  cout << s.romanToInt("LVIII") << endl;
  cout << s.romanToInt("MCMXCIV") << endl;
  return 0;
}
