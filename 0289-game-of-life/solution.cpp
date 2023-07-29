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
  int neighbors(vector<vector<int>>& matrix, int row, int col, int n, int m) {
    int startRow = max(row - 1, 0), startCol = max(col - 1, 0),
        endRow = min(row + 1, n - 1), endCol = min(col + 1, m - 1), count = 0;
    for (int i = startRow; i <= endRow; i++) {
      for (int j = startCol; j <= endCol; j++) {
        if (i == row && j == col) continue;
        if (matrix[i][j] == 1) count++;
      }
    }
    return count;
  }
  void gameOfLife(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<pair<int, int>> toDie, toLive;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int count = neighbors(matrix, i, j, n, m);
        if (matrix[i][j] == 1 && (count < 2 || count > 3)) {
          toDie.push_back({i, j});
        }
        if (matrix[i][j] == 0 && count == 3) {
          toLive.push_back({i, j});
        }
      }
    }
    for (auto cell : toDie) {
      matrix[cell.first][cell.second] = 0;
    }
    for (auto cell : toLive) {
      matrix[cell.first][cell.second] = 1;
    }
  }
};
class Optimal {
 public:
  void gameOfLife(vector<vector<int>>& board) {
    int m = board.size(), n = m ? board[0].size() : 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int count = 0;
        for (int I = max(i - 1, 0); I < min(i + 2, m); ++I)
          for (int J = max(j - 1, 0); J < min(j + 2, n); ++J)
            count += board[I][J] & 1;
        if (count == 3 || count - board[i][j] == 3) {
          // board[i][j] |= 1<<1 --- set the 2nd bit to new state.
          board[i][j] |= 2;
        }
      }
    }
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        board[i][j] >>= 1;  // replace the old state with the new state by
                            // shifting all values one bit to the right
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
  s.gameOfLife(testMatrix);
  cout << "\tgameOfLife (mine), result = \n";
  if (matrix.size() < 100) {
    Output::matrixPrint(testMatrix, 2);
  }
  cout << endl;

  testMatrix = matrix;
  o.gameOfLife(testMatrix);
  cout << "\tgameOfLife (optimal), result = \n";
  if (matrix.size() < 100) {
    Output::matrixPrint(testMatrix, 2);
  }
  cout << endl;
  return 0;
}
int main() {
  vector<vector<int>> matrix;
  matrix = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
  test(matrix);
  matrix = {{1, 1}, {1, 0}};
  test(matrix);
  return 0;
}