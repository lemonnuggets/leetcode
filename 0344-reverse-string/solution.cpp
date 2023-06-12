#include "../modules/index.h"
class Solution {
 public:
  int reverseString(vector<char>& s) {
    char temp;
    int a, b;
    for (int i = 0; i < s.size() / 2; i++) {
      a = i;
      b = s.size() - i - 1;
      temp = s[a];
      s[a] = s[b];
      s[b] = temp;
    }
    return 0;
  }
};
class Optimal {
 public:
  int reverseString(vector<char>& s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
      swap(s[i], s[j]);
    }
    return 0;
  }
};
int test(vector<char> charArray) {
  Solution s = Solution();
  Optimal o = Optimal();
  // TODO: Find a way to time functions and get value for functions that operate
  // by reference

  cout << "\nS (size = " << charArray.size() << ") = \t";
  Output::vectorPrint(charArray);
  cout << endl;

  vector<char> copy = charArray;
  cout << "\tReverse String (mine), result = \t";
  s.reverseString(copy);
  Output::vectorPrint(copy);
  cout << endl;

  copy = charArray;
  cout << "\tReverse String (optimal), result = \t";
  o.reverseString(copy);
  Output::vectorPrint(copy);
  cout << endl;
  return 0;
}
int main() {
  vector<char> x = {'h', 'e', 'l', 'l', 'o'};
  test(x);
  x = {'H', 'a', 'n', 'n', 'a', 'h'};
  test(x);
  return 0;
}