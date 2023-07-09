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
  int lengthOfLastWord(string str) {
    int n = str.size();
    int i = n - 1;
    int length = 0;
    while (i >= 0) {
      if (str[i] == ' ') {
        if (length > 0) {
          return length;
        }
      } else {
        length++;
      }
      i--;
    }
    return length;
  }
};
class Optimal {
 public:
  int lengthOfLastWord(string str) {
    int n = str.size();
    int i = n - 1;
    int length = 0;
    while (i >= 0) {
      if (str[i] == ' ') {
        if (length > 0) {
          return length;
        }
      } else {
        length++;
      }
      i--;
    }
    return length;
  }
};
int test(string str) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nstr (size = " << str.size() << ") = \t";
  cout << str << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::lengthOfLastWord, s, str);
  cout << "\tlengthOfLastWord (mine), result = \t\t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result =
      measureMethodPerformance(ITERATIONS, &Optimal::lengthOfLastWord, o, str);
  cout << "\tlengthOfLastWord (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  string x;
  x = "Hello World";
  test(x);
  x = "   fly me   to   the moon  ";
  test(x);
  x = "luffy is still joyboy";
  test(x);
  return 0;
}