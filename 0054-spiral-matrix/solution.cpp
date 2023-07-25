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
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n <= 0) {
      return {};
    }
    int m = matrix[0].size();
    vector<int> res;
    int rowStart = 0, rowEnd = n, colStart = 0, colEnd = m;
    while (rowStart < rowEnd && colStart < colEnd) {
      for (int i = colStart; i < colEnd; i++) {
        res.push_back(matrix[rowStart][i]);
      }
      rowStart++;
      if (rowEnd - rowStart <= 0) {
        break;
      }

      for (int i = rowStart; i < rowEnd; i++) {
        res.push_back(matrix[i][colEnd - 1]);
      }
      colEnd--;
      if (colEnd - colStart <= 0) {
        break;
      }

      for (int i = colEnd - 1; i >= colStart; i--) {
        res.push_back(matrix[rowEnd - 1][i]);
      }
      rowEnd--;
      if (rowEnd - rowStart <= 0) {
        break;
      }

      for (int i = rowEnd - 1; i >= rowStart; i--) {
        res.push_back(matrix[i][colStart]);
      }
      colStart++;
      if (colEnd - colStart <= 0) {
        break;
      }
    }
    return res;
  }
};
class Optimal {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n <= 0) {
      return {};
    }
    int m = matrix[0].size();
    vector<int> res;
    int rowStart = 0, rowEnd = n, colStart = 0, colEnd = m;
    while (rowStart < rowEnd && colStart < colEnd) {
      for (int i = colStart; i < colEnd; i++) {
        res.push_back(matrix[rowStart][i]);
      }
      rowStart++;
      if (rowEnd - rowStart <= 0) {
        break;
      }

      for (int i = rowStart; i < rowEnd; i++) {
        res.push_back(matrix[i][colEnd - 1]);
      }
      colEnd--;
      if (colEnd - colStart <= 0) {
        break;
      }

      for (int i = colEnd - 1; i >= colStart; i--) {
        res.push_back(matrix[rowEnd - 1][i]);
      }
      rowEnd--;
      if (rowEnd - rowStart <= 0) {
        break;
      }

      for (int i = rowEnd - 1; i >= rowStart; i--) {
        res.push_back(matrix[i][colStart]);
      }
      colStart++;
      if (colEnd - colStart <= 0) {
        break;
      }
    }
    return res;
  }
};
int test(vector<vector<int>>& matrix) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nmatrix = \n";
  Output::matrixPrint(matrix);
  cout << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::spiralOrder, s, matrix);
  cout << "\tspiralOrder (mine), result = \t\t";
  if (result.second.size() < 100) {
    Output::vectorPrint(result.second);
  }
  cout << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result =
      measureMethodPerformance(ITERATIONS, &Optimal::spiralOrder, o, matrix);
  cout << "\tspiralOrder (optimal), result = \t";
  if (result.second.size() < 100) {
    Output::vectorPrint(result.second);
  }
  cout << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  vector<vector<int>> matrix;
  matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  test(matrix);
  matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  test(matrix);
  return 0;
}