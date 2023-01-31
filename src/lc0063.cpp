typedef vector<int> vi;
typedef vector<vi> vvi;

class Solution {
public:
  // grid: mxn grid
  // i,j: coords to check
  // m,n: grid dims
  int dfs(vvi &grid, int i, int j, int m, int n) {
    if (i >= m || j >= n || grid[i][j] == 1) {
      return 0;
    }

    // already visited
    if (grid[i][j] > 1) {
      return grid[i][j] - 2;
    }

    int res = 0;

    res += dfs(grid, i + 1, j, m, n);
    res += dfs(grid, i, j + 1, m, n);

    grid[i][j] = res + 2;
    return res;
  }

  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    if (obstacleGrid[m - 1][n - 1] == 0) {
      obstacleGrid[m - 1][n - 1] = 3;
    }
    return dfs(obstacleGrid, 0, 0, m, n);
  }
};
