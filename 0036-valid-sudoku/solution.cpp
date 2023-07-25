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
  int intFromChar(char ch) { return ch - '0'; }
  bool isValidSudoku(vector<vector<char>>& board) {
    int n = board.size();
    for (int i = 0; i < 9; i++) {
      vector<bool> seen(9, false);
      for (int j = 0; j < 9; j++) {
        if (board[i][j] == '.') continue;

        int x = intFromChar(board[i][j]);
        if (seen[x]) {
          return false;
        }
        seen[x] = true;
      }
    }

    for (int j = 0; j < 9; j++) {
      vector<bool> seen(9, false);
      for (int i = 0; i < 9; i++) {
        if (board[i][j] == '.') continue;

        int x = intFromChar(board[i][j]);
        if (seen[x]) {
          return false;
        }
        seen[x] = true;
      }
    }

    for (int k = 0; k < 9; k += 3) {
      for (int l = 0; l < 9; l += 3) {
        vector<bool> seen(9, false);
        for (int i = k; i < k + 3; i++) {
          for (int j = l; j < l + 3; j++) {
            if (board[i][j] == '.') continue;

            int x = intFromChar(board[i][j]);
            if (seen[x]) {
              return false;
            }
            seen[x] = true;
          }
        }
      }
    }
    return true;
  }
};
class Optimal {
 public:
  bool isValidSudoku(vector<vector<char>>& board) { return false; }
};
int test(vector<vector<char>>& board) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\nboard = \n";
  Output::matrixPrint(board);
  cout << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::isValidSudoku, s, board);
  cout << "\tisValidSudoku (mine), result = \t\t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result =
      measureMethodPerformance(ITERATIONS, &Optimal::isValidSudoku, o, board);
  cout << "\tisValidSudoku (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  vector<vector<char>> board;
  board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
           {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
           {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
           {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
           {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
           {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
           {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
           {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
           {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  test(board);
  board = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
           {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
           {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
           {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
           {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
           {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
           {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
           {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
           {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
  test(board);
  return 0;
}