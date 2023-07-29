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
  void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n <= 0) return;
    int m = matrix[0].size();

    vector<pair<int, int>> zeroes;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] != 0) continue;
        zeroes.push_back({i, j});
      }
    }

    for (auto zero : zeroes) {
      for (int j = 0; j < m; j++) {
        matrix[zero.first][j] = 0;
      }
      for (int i = 0; i < n; i++) {
        matrix[i][zero.second] = 0;
      }
    }
  }
};
class Optimal {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    // store states of each row in the first of that row, and store states of
    // each column in the first of that column. Because the state of row0 and
    // the state of column0 would occupy the same cell, I let it be the state of
    // row0, and use another variable "col0" for column0. In the first phase,
    // use matrix elements to set states in a top-down way. In the second phase,
    // use states to set matrix elements in a bottom-up way.
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
      if (matrix[i][0] == 0) col0 = 0;
      for (int j = 1; j < cols; j++)
        if (matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
    }

    for (int i = rows - 1; i >= 0; i--) {
      for (int j = cols - 1; j >= 1; j--)
        if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
      if (col0 == 0) matrix[i][0] = 0;
    }
  }
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
  s.setZeroes(testMatrix);
  cout << "\tsetZeroes (mine), result = \n";
  if (matrix.size() < 100) {
    Output::matrixPrint(testMatrix, 2);
  }
  cout << endl;

  testMatrix = matrix;
  o.setZeroes(testMatrix);
  cout << "\tsetZeroes (optimal), result = \n";
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
  matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  test(matrix);
  return 0;
}