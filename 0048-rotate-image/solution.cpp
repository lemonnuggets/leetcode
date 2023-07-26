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
  void swap(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
  }
  int rotateLayer(vector<vector<int>>& matrix, int layer) {
    int n = matrix.size();
    int startRow = layer, endRow = n - layer, startCol = layer,
        endCol = n - layer;
    if ((endRow - startRow) * (endCol - startCol) <= 1) {
      return -1;
    }
    int temp;
    for (int i = startRow; i < endRow - 1; i++) {
      temp = matrix[startRow][i];
      swap(temp, matrix[i][endCol - 1]);
      swap(temp, matrix[endRow - 1][n - i - 1]);
      swap(temp, matrix[n - i - 1][startCol]);
      swap(temp, matrix[startCol][i]);
    }
    return 0;
  }
  void rotate(vector<vector<int>>& matrix) {
    int layer = 0, res = 0;
    while (res == 0) {
      res = rotateLayer(matrix, layer++);
    }
  }
};
class Optimal {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size() - 1;
    for (int i = 0; i <= n / 2; i++) {
      for (int j = i; j < n - i; j++) {
        int copy = matrix[i][j];
        matrix[i][j] = matrix[n - j][i];
        matrix[n - j][i] = matrix[n - i][n - j];
        matrix[n - i][n - j] = matrix[j][n - i];
        matrix[j][n - i] = copy;
      }
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
  s.rotate(testMatrix);
  cout << "\trotate (mine), result = \n";
  if (matrix.size() < 100) {
    Output::matrixPrint(testMatrix, 2);
  }
  cout << endl;

  testMatrix = matrix;
  o.rotate(testMatrix);
  cout << "\trotate (optimal), result = \n";
  if (matrix.size() < 100) {
    Output::matrixPrint(testMatrix, 2);
  }
  cout << endl;
  return 0;
}
int main() {
  vector<vector<int>> matrix;
  matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  test(matrix);
  matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  test(matrix);
  return 0;
}