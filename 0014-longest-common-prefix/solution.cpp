#include "../modules/index.h"
#define ITERATIONS 50
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

  cout << "\nX = ";
  Output::vectorPrint(x);
  cout << endl;

  auto result = measureMethodPerformance(ITERATIONS,
                                         &Solution::longestCommonPrefix, s, x);

  cout << "\tLongest Common Prefix = " << result.second
       << "\t\tTime Taken: " << result.first << endl;
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