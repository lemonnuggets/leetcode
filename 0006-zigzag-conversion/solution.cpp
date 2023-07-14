#include "../modules/index.h"
#define ITERATIONS 100
static auto _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();
class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows < 1) {
      return "";
    }
    if (numRows == 1) {
      return s;
    }
    int totalJump = (numRows - 1) * 2;
    int n = s.size();
    string res = "";
    int row = 0;
    while (row < numRows) {
      int jump2 = row * 2;
      int jump1 = totalJump - jump2;
      int i = row;
      if (jump2 == 0) {
        res += s[i];
      }
      while (i < n) {
        if (jump2 != 0) {
          res += s[i];
        }
        i += jump1;
        if (i >= n) {
          break;
        }
        if (jump1 != 0) {
          res += s[i];
        }
        i += jump2;
      }
      row++;
    }
    return res;
  }
};
class Optimal {
 public:
  string convert(string s, int numRows) {
    if (numRows <= 1) return s;

    vector<string> v(numRows, "");

    int j = 0, dir = -1;

    for (int i = 0; i < s.length(); i++) {
      if (j == numRows - 1 || j == 0) dir *= (-1);

      v[j] += s[i];

      if (dir == 1)
        j++;

      else
        j--;
    }

    string res;

    for (auto &it : v) res += it;

    return res;
  }
};
int test(string argument, int numRows) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nargument (size = " << argument.size() << ") = \t";
  if (argument.size() < 100) cout << argument << endl;
  cout << "\nnumRows  = " << numRows << endl;

  auto result = measureMethodPerformance(ITERATIONS, &Solution::convert, s,
                                         argument, numRows);
  cout << "\tconvert (mine), result = \t\t";
  if (result.second.size() < 100) cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::convert, o, argument,
                                    numRows);
  cout << "\tconvert (optimal), result = \t\t";
  if (result.second.size() < 100) cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  string x;
  int y;
  x = "PAYPALISHIRING";
  y = 3;
  test(x, y);
  x = "A";
  y = 1;
  test(x, y);
  x = "PAYPALISHIRING";
  y = 4;
  test(x, y);
  x = "PAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPA"
      "YPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYP"
      "ALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPAL"
      "ISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALIS"
      "HIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHI"
      "RINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRI"
      "NGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRING"
      "PAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPA"
      "YPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYP"
      "ALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPAL"
      "ISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALIS"
      "HIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHI"
      "RINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRI"
      "NGPAYPALISHIRINGPAYPALISHIRINGPAYPALISHIRING";
  y = 1000;
  test(x, y);
  y = 500;
  test(x, y);
  y = 100;
  test(x, y);
  y = 10;
  test(x, y);
  return 0;
}