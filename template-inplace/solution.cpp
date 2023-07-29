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
  void func(vector<vector<int>>& matrix) {}
};
class Optimal {
 public:
  void func(vector<vector<int>>& matrix) {}
};
int test(vector<vector<int>>& matrix) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nmatrix (n = " << matrix.size() << ") = \n";
  if (matrix.size() < 100) {
    Output::matrixPrint(matrix);
  }
  cout << endl;

  vector<vector<int>> testMatrix;

  testMatrix = matrix;
  s.func(testMatrix);
  cout << "\tfunc (mine), result = \n";
  if (matrix.size() < 100) {
    Output::matrixPrint(testMatrix, 2);
  }
  cout << endl;

  testMatrix = matrix;
  o.func(testMatrix);
  cout << "\tfunc (optimal), result = \n";
  if (matrix.size() < 100) {
    Output::matrixPrint(testMatrix, 2);
  }
  cout << endl;
  return 0;
}
int main() {
  vector<vector<int>> matrix;
  matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  test(matrix);
  return 0;
}