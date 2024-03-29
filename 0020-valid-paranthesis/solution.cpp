#include "../modules/index.h"
#define ITERATIONS 50
// using stack data structure from c++ stl
class Solution {
 public:
  bool isOpening(char c) { return c == '(' || c == '[' || c == '{'; }
  bool isClosing(char c) { return !isOpening(c); }
  bool isMatching(char a, char b) {
    if (a == '(' && b == ')') return true;
    if (a == '[' && b == ']') return true;
    if (a == '{' && b == '}') return true;
    return false;
  }
  bool isValid(string s) {
    stack<char> d;
    for (int i = 0; i < s.size(); i++) {
      if (isOpening(s[i])) {
        d.push(s[i]);
      } else {
        if (d.size() > 0 && isMatching(d.top(), s[i])) {
          d.pop();
        } else {
          return false;
        }
      }
    }
    if (d.size() > 0) return false;
    return true;
  }
};
int test(string str) {
  Solution s = Solution();
  int duration;

  cout << "\nStr = " << str << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::isValid, s, str);

  cout << "\tTime Taken: " << result.first << "\t\tisValid = " << result.second
       << endl;
  return 0;
}
int main(int argc, char const *argv[]) {
  test("()");
  test("()[]{}");
  test("(]");
  test("((()))]");
  return 0;
}
