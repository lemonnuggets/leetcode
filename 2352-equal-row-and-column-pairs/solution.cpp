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
  int getColumnsEqualToRow(vector<vector<int>>& grid, int rowIndex) {
    int n = grid.size();
    int count = 0;
    bool isColumnEqual;
    for (int col = 0; col < n; col++) {
      isColumnEqual = true;
      for (int row = 0; row < n; row++) {
        if (grid[rowIndex][row] != grid[row][col]) {
          isColumnEqual = false;
          break;
        }
      }
      if (isColumnEqual) count++;
    }
    return count;
  }
  int equalPairs(vector<vector<int>>& grid) {
    int count = 0;
    int n = grid.size();
    for (int i = 0; i < n; i++) {
      count += getColumnsEqualToRow(grid, i);
    }
    return count;
  }
};
class Optimal {
 public:
  int equalPairs(vector<vector<int>>& grid) {
    map<vector<int>, int> hashmap;
    int ans = 0;
    int n = grid.size();
    for (int i = 0; i < n; i++) {
      hashmap[grid[i]]++;
    }
    vector<int> col(n);
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < n; i++) {
        col[i] = grid[i][j];
      }
      ans += hashmap[col];
    }
    return ans;
  }
};
class Optimal2 {
 public:
  int equalPairs(vector<vector<int>>& grid) {
    map<vector<int>, int> hashmap;
    int cnt = 0;
    int n = grid.size();

    for (int i = 0; i < n; i++) {
      hashmap[grid[i]]++;
    }

    vector<int> col(n);
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < n; i++) col[i] = grid[i][j];

      // NOTE: inserts (key, 0) if not exist
      cnt += hashmap[col];
    }

    return cnt;
  }
};
int test(vector<vector<int>>& grid) {
  Solution s = Solution();
  Optimal o = Optimal();
  Optimal2 o2 = Optimal2();
  Timer t = Timer();

  cout << "\nGrid (size = " << grid.size() << ") = \n";
  // Output::vectorPrint(grid);
  // cout << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::equalPairs, s, grid);
  cout << "\tEqual Pairs (mine), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::equalPairs, o, grid);
  cout << "\tEqual Pairs (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result =
      measureMethodPerformance(ITERATIONS, &Optimal2::equalPairs, o2, grid);
  cout << "\tEqual Pairs (optimal2), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
vector<vector<int>> generateRandomGrid(int n) {
  vector<vector<int>> grid(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      grid[i][j] = rand() % 10;
    }
  }
  return grid;
}
int main() {
  vector<vector<int>> x = {{3, 2, 1}, {1, 7, 6}, {2, 7, 7}};
  test(x);
  x = {{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
  test(x);
  x = generateRandomGrid(1000);
  test(x);
  return 0;
}