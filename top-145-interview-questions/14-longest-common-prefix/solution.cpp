#include "../modules/index.h"
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
int test(vector<string>& x) {
  Solution s = Solution();
  Timer t = Timer();
  int duration;

  cout << "\nX = ";
  Output::vector(x);
  cout << endl;

  t.startClock();
  string prefix = s.longestCommonPrefix(x);
  duration = t.stopClock();

  cout << "\tLongest Common Prefix = " << prefix
       << "\t\tTime Taken: " << duration << endl;
  return 0;
}
int main() {
  Solution s = Solution();
  vector<string> ra;
  ra = {"hello", "help", "heaven", "heathen"};
  test(ra);
  ra = {"flower", "flow", "flight"};
  test(ra);
  ra = {"dog", "racecar", "car"};
  test(ra);
  return 0;
}