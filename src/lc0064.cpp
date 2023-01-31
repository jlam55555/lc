class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    for (int i = m - 1; i >= 0; --i) {
      for (int j = n - 1; j >= 0; --j) {
        if (i == m - 1 && j == n - 1)
          continue;

        int min_path = INT_MAX;
        if (i != m - 1)
          min_path = min(min_path, grid[i + 1][j]);
        if (j != n - 1)
          min_path = min(min_path, grid[i][j + 1]);

        grid[i][j] += min_path;
      }
    }

    return grid[0][0];
  }
};
