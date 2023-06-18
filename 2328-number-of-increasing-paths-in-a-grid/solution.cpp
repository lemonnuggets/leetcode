#include "../modules/index.h"
#define ITERATIONS 1
int offsets[5][2] = {{0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
static int MOD = 1e9 + 7;
static vector<int> dirs = {0, 1, 0, -1, 0};
class Solution {
 public:
  int countPathsDfs(vector<vector<int>>& grid, set<pair<int, int>>& seen, int a,
                    int b) {
    int n = grid.size();
    int m = grid[0].size();

    int totalPaths = 0;
    if (a < 0 || a >= n || b < 0 || b >= m) return totalPaths;

    pair<int, int> current = {a, b};
    auto insertionResult = seen.emplace(current);
    if (!insertionResult.second) return totalPaths;

    totalPaths = 1;
    for (int i = 0; i < 5; i++) {
      int x = a + offsets[i][0];
      int y = b + offsets[i][1];
      int paths = countPathsDfs(grid, seen, x, y);
      if (paths == 0) continue;
      if (!(grid[x][y] > grid[a][b])) continue;
      totalPaths = (totalPaths + paths) % (int)(1e9 + 7);
      // cout << "curr = (" << a << ", " << b << ")"
      //      << "\tnext = (" << x << ", " << y << ")"
      //      << "\tpaths = " << paths << "\ttotalPaths = " << totalPaths <<
      //      endl;
    }

    seen.erase(insertionResult.first);
    return totalPaths;
  }
  int countPaths(vector<vector<int>>& grid) {
    set<pair<int, int>> seen;
    return countPathsDfs(grid, seen, 0, 0);
  }
};
class Optimal {
 public:
  vector<vector<long>> memo;
  long dp(vector<vector<int>>& grid, int i, int j) {
    long result = 1;  // Contribution of current cell as an increasing sequence.
    if (memo[i][j] != -1)  // Return the cached results if they exist.
      return memo[i][j];
    for (int d = 0; d < 4; d++) {  // Check all 4 directions.
      int x = i + dirs[d], y = j + dirs[d + 1];
      if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() &&
          grid[x][y] > grid[i][j])
        result = (result + dp(grid, x, y)) %
                 MOD;  // Add the total number of cells in the longest path for
                       // all directions.
    }
    return memo[i][j] = result;
  }
  int countPaths(vector<vector<int>>& grid) {
    long result = 0;
    memo.resize(grid.size(), vector<long>(grid[0].size(), -1));
    for (int i = 0; i < grid.size();
         i++)  // For each cell as a starting point calculate the number of
               // increasing paths it can contribute.
      for (int j = 0; j < grid[0].size(); j++)
        result = (result + dp(grid, i, j)) % MOD;
    return result;
  }
};
int test(vector<vector<int>>& grid) {
  Solution s = Solution();
  Optimal o = Optimal();
  Timer t = Timer();

  cout << "\ngrid (n = " << grid.size() << ")(m = " << grid[0].size()
       << ") = \t";
  Output::vectorPrint(grid);
  cout << endl;

  auto result =
      measureMethodPerformance(ITERATIONS, &Solution::countPaths, s, grid);
  cout << "\tcountPaths (mine), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;

  result = measureMethodPerformance(ITERATIONS, &Optimal::countPaths, o, grid);
  cout << "\tcountPaths (optimal), result = \t";
  cout << result.second << endl;
  cout << "\t\t\t\tTime Taken: " << result.first << endl;
  return 0;
}
int main() {
  vector<vector<int>> grid;
  grid = {{1}, {2}};
  test(grid);
  grid = {{1, 1}, {3, 4}};
  test(grid);
  return 0;
}